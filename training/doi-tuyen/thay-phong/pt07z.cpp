#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)

int f[MAX_N];
int g[MAX_N];
vector<int> adj[MAX_N];
int ans = 0;

void DFS(int u , int father) {
	vector<int> tm;
	for (auto v : adj[u]) {
		if (v != father) {
			DFS(v , u);
			tm.push_back(f[v]);
		}
	}
	sort(tm.begin() , tm.end() , greater<int>());
	if (!tm.empty()) {
		f[u] = tm[0] + 1;
		if (tm.size() >= 2) g[u] = tm[0] + tm[1] + 2;
	}
	ans = max({ans , g[u] , f[u]});
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.inp","r",stdin);
	int n , m; cin >> n;
	for (int i = 1 ; i < n ; i++) {
		int u , v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	DFS(1 , -1);
	cout << ans;
	return 0;
}