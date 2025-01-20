#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define fi freopen("BFSsortreach.inp","r",stdin);
#define fo freopen("BFSsortreach.out","w",stdout);


int n , m;
vector <int> a[50005];

int BFS(int s) {
	int dist[50005];
	bool visited[50005];
	memset(visited,false,sizeof(visited));
	queue <int> q;
	visited[s] = true;
	q.push(s);
	memset(dist , -1 , sizeof(dist));
	dist[s] = 0;
	while (!q.empty()) {
		int u = q.front();
		int v;
		q.pop();
		for (int i = 0 ; i < (int) a[u].size() ; i++){
			v = a[u][i];
			if (dist[v] == -1) {
				dist[v] = dist[u] + 6;
				q.push(v);
			}
		} 


	}
	for (int i = 1 ; i <= n ; i++){
		if (i != s) 
		cout << dist[i] << " " ;
	}
	cout << endl;

	return 0;
}

int main() {
	boost;
	fi;fo;
	int q; cin >> q;
	while (q --){ 
		cin >> n >> m;
		for (int i = 0 ; i <= n ; i++) a[i].clear();
		int u , v;
		for (int i = 0 ; i < m ; i++) {
			cin >> u >> v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		int s; cin >> s;

		BFS(s);

	}


	return 0;
}