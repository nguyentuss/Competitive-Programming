#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (3e5 + 7)
#define int long long

int sz[MAX_N];
int f[MAX_N] , H[MAX_N];
int P[MAX_N][20];
vector <int> adj[MAX_N];
int n;

void buildtable() {
	for (int u = 1 ; u <= n ; u++) {
		for (int k = 1 ; k < 20 ; k ++) {
			P[u][k] = -1;
		}
	}
	for (int k = 1 ; k < 20 ;k++) {
		for (int u = 1 ; u <= n ; u++) {
			if (P[u][k - 1] != -1){
				P[u][k] = P[P[u][k - 1]][k - 1];
			}
		}
	}
}

int process(int u , int height) {
	while (H[u] > height) {
		for (int k = 19 ; k >= 0 ; k--) {
			if (P[u][k] != -1 && H[P[u][k]] >= height) {
				u = P[u][k];
				break;
			}
		}
	}
	return u;
}

void DFS(int u , int father) {
	sz[u] = 1;
	P[u][0] = father;
	for (auto v : adj[u]) {
		if (v != father) {
			H[v] = H[u] + 1;
			DFS(v , u);
			sz[u] += sz[v];
		}
	}

	for (auto v : adj[u]) {
		if (v != father) {
			f[u] += sz[v]*(sz[u] - sz[v] - 1) + sz[v]*2;
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.inp","r",stdin);
	int n , x , y; cin >> n >> x >> y;
	for (int i = 1 ; i < n ; i++) {
		int u , v ; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	DFS(x , -1);
	int ans = 0;
	int tmp = process(y , 1);
	for (auto v : adj[x]) {
		if (v == tmp) {
			ans += sz[v]*(sz[x] - sz[v] - 1) + (sz[v] - sz[y])*2 + sz[y];
		}
		else {
			ans += sz[v]*(sz[x] - sz[v] - sz[y] - 1) + sz[v]*2;
		}
	}
	//for (int i = 1 ; i <= n ; i++) {
	//	cout << f[i] << " ";
	//}
	for (int i = 1 ; i <= n ; i++) {
		if (i != x){
			ans += f[i];
		}
	}
	cout << ans;
	return 0;
}