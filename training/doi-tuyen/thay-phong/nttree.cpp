#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)
#define ii pair<int ,int>
#define int long long

vector<ii> adj[MAX_N];
int sz[MAX_N];
int down[MAX_N];
int up[MAX_N];
int n;

void DP1(int u , int father) {
	sz[u] = 1;
	for (auto x : adj[u]) {
		int v = x.first;
		if (v != father) {
			DP1(v , u);
			sz[u] += sz[v];
		}
	}
}
void DP2(int u , int father) {
	for (auto x : adj[u]) {
		int v = x.first , uv = x.second;
		if (v != father) {
			DP2(v , u);
			down[u] += uv*sz[v] + down[v];
		}
	}
}

void DP3(int u , int father) {
	for (auto x : adj[u]) {
		int v = x.first , uv = x.second;
		if (v != father) {	
			up[v] += (down[u] - down[v] - sz[v]*uv) + up[u] + (n - sz[v])*uv;
			DP3(v , u);
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.inp","r",stdin);
	cin >> n;
	for (int i = 1 ; i < n ; i++) {
		int u , v , c; cin >> u >> v >> c;
		adj[u].push_back(ii(v , c));
		adj[v].push_back(ii(u , c));
	}
	DP1(1 , -1);
	DP2(1 , -1);
	DP3(1 , -1);
	int ans = 0;
	for (int i = 1 ; i <= n ; i++) {
		ans += down[i] + up[i];
	}
	cout << ans/2;
	return 0;
}