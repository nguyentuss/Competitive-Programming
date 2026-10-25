#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e3 + 7)

int n ,m;
vector<int> adj[MAX_N];
bool vis[MAX_N];
int res = 0;

int DFS(int u) {
	vis[u] = true;
	int total = 0;
	for (auto v : adj[u]) {
		if (!vis[v]) {
			int subtree = DFS(v);
			if (subtree % 2 == 0) {
				res++;
			}
			else {
				total += subtree;
			}
		}
	}
	return (total + 1);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.inp","r",stdin);
	cin >> n >> m;
	for (int i = 0 ; i < m ; i++) {
		int u , v ; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	DFS(1);
	cout << res;

	return 0;
}