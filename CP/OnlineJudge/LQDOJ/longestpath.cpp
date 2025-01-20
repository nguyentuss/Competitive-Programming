#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#pragma GCC optimize("Ofast")

vector <int> a[100007];

int dist[100007] = {-1};
bool visited[100007];
queue <int> q;
int ans = 0;

int BFS(int start) {
	visited[start] = true;
	q.push(start);
	dist[start] = 0;
	while (!q.empty()) {
		int u = q.front();
		int v;
		q.pop();
		for (int i = 0 ; i < (int) a[u].size() ; i++){
			v = a[u][i];
			dist[v] = max(dist[v] , dist[u] + 1);
			ans = max(ans , dist[v]);
			q.push(v);
			visited[v] = true;
		} 


	}


	return 0;
}

int main() {
//	boost;

	int n , m  ; cin >> n >> m;
	int u , v;
	for (int i = 0 ; i < m ; i++) {
		cin >> u >> v;
		a[u].push_back(v);
		//a[v].push_back(u);
	}
	
	for (int i = 1 ; i <= n ; i++) {
		if (!visited[i])
			BFS(i);
	}	
	cout << ans;


	return 0;
}