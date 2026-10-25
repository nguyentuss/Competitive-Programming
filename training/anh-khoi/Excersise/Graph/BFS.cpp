#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

vector <int> a[1000];

int dist[1000];

int BFS() {
	bool visited[1000];
	memset(visited,false,sizeof(visited));
	queue <int> q;
	visited[1] = true;
	q.push(1);
	memset(dist , -1 , sizeof(dist));
	dist[1] = 1;
	while (!q.empty()) {
		int u = q.front();
		int v;
		q.pop();
		for (int i = 0 ; i < (int) a[u].size() ; i++){
			v = a[u][i];
			if (!visited[v] && dist[v] == -1) {
				dist[v] = dist[u] + 1;
				q.push(v);
				visited[v] = true;
			}
		} 


	}


	return 0;
}

int main() {
	boost;

	int n ; cin >> n;
	int u , v;
	for (int i = 0 ; i < n ; i++) {
		cin >> u >> v;
		a[u].push_back(v);
		//a[v].push_back(u);
	}

	BFS();


	return 0;
}