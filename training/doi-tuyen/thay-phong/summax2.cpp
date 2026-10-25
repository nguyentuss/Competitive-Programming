#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (2*1e5 + 7)
#define int long long

int val[MAX_N];
vector<int> adj[MAX_N];
int f[MAX_N]; // kh tính  u
int g[MAX_N]; // tính ca u

void DFS(int u , int father) {
	g[u] = val[u];
	for (auto v : adj[u]) {
		if (v != father) {
			DFS(v , u);
			g[u] += f[v];
			f[u] += max(f[v] , g[v]);
		}
	}

}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test1.inp","r",stdin);
	int n; cin >> n;
	for (int i = 1; i <= n ; i++) 
		cin >> val[i];
	int root = 0;
	for (int i = 1 ; i <= n ; i++) {
		int x; cin >> x;
		if (x != 0) {
			adj[i].push_back(x);
			adj[x].push_back(i);
		}
		else {
			root = i;
		}
	}
	//cout << root;
	DFS(root , -1);
	for (int i = 1 ; i <= n ; i++) ans = max(ans , max(f[root] , g[root]));
	return 0;
}