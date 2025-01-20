#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (2*1e5 + 7)
#define inf (int) (1e9 + 7)

int down[MAX_N];
int f[MAX_N];
bool vis[MAX_N];
vector<int> adj[MAX_N];

void DFS1(int u , int father) {
	if (vis[u]) down[u] = 0;
	else down[u] = inf;
	for (auto v : adj[u]) {
		if (v != father) {
			DFS1(v , u);
			down[u] = min(down[u] , down[v] + 1);
		}
	}
}

void DFS2(int u , int father) {
	if (father == -1) f[u] = down[u];
	else f[u] = min(down[u] , f[father] + 1);
	for (auto v : adj[u]) {
		if (v != father)
			DFS2(v , u);
	}
}

bool DFS3(int u , int father , int len) {
	int sl = 0;
	for (auto v : adj[u]) {
		if (v != father) {
			if (DFS3(v , u , len + 1)) return 1;
			sl++;
		}
	}
	if (!sl) return (f[u] > len);
	else return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	freopen("test.inp","r",stdin);
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		for (int i = 1 ; i <= n ; i++) {
			vis[i] = false;
			adj[i].clear();
		}
		for (int i = 1 ; i <= k ;  i++) {
			int x; cin >> x;
			vis[x] = true;
		}
		for (int i = 1 ; i < n ; i++) {
			int u , v; cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		DFS1(1 , -1);
		DFS2(1 , -1);
		for (int i = 1 ; i <= n ; i++) {
			cout << f[i] << " ";
		}
		if (DFS3(1 , -1 , 0)) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}

	return 0;
}