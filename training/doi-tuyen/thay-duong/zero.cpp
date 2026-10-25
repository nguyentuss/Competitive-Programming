#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)

vector <int> adj[MAX_N];
int w[MAX_N];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	freopen("zero.inp","r",stdin);
	freopen("zero.out","w",stdout);
	int t; cin >> t; 
	while (t--) {
		for (int i = 1 ; i < MAX_N ; i++) adj[i].clear();
		int n; cin >> n;
		for (int i = 1 ; i < n ; i++) {
			int u , v ; cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		for (int i = 1 ; i <= n ; i++) 
			cin >> w[i];
		int ans = 0;
		for (int i = 1 ; i <= n ; i++) {
			if (adj[i].size() >= 2 && w[i] >= 1) ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}