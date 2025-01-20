#include <bits/stdc++.h>

using namespace std;

vector <int> adj[100007];
vector <bool> visited(100007);
int cnt = 0;

void DFS(int u) {
	visited[u] = true;
	cnt ++;
	for (auto v : adj[u]) {
		if (visited[v] == false) {
			DFS(v);
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) {
     	   adj[i].clear();
     	   visited[i] = false;
    	}	
		for (int i = 1 ; i < n ; i++) {
			int u , v , w; cin >> u >> v >> w;
			if (w == 0) {
				adj[u].push_back(v);
				adj[v].push_back(u);
			}
		}
		long long res = 1LL * n*(n - 1)/2;
		for (int i = 1 ; i <= n ; i++) {
			if (!visited[i]) {
				cnt = 0;
				DFS(i);
				res -= cnt*(cnt - 1)/2;
			}
		}
		cout << res << '\n';
	}
	return 0;
}