#include <bits/stdc++.h>

using namespace std;

int n , m;
bool visited[2007];
vector <int> adj[2007];

void DFS(int u) {
	visited[u] = true;
	for (auto v : adj[u]) {
		if (!visited[v]) {
			DFS(v);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1 ; i <= m ; i++) {
		int u , v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int res = m - n;
	for (int i = 1 ; i <= n ; i++) {
		if (!visited[i]) {
			res ++;
			//visited[i] = true;
			DFS(i);
		}
	}
	cout << res;
	return 0;
}