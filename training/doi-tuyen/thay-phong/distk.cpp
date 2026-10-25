#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (5e4 + 7)
#define int long long

int g[MAX_N][207];
vector<int> adj[MAX_N];
int f[MAX_N];
int n , k;
int sum[207];

void DFS(int u , int father) {
	g[u][0] = 1;
	int cnt = 0;
	for (auto v : adj[u]) {
		if (v != father) {
			DFS(v , u);
			for (int j = 1 ; j <= k ; j++) {
				g[u][j] += g[v][j - 1];
			}
		}
	}
	memset(sum , 0 , sizeof sum);
	for (auto v : adj[u]){
		if (v != father) {
			for (int j = 0 ; j < k ; j++) {	
				int last = k - j - 1;
				if (last <= 0) f[u] += g[v][j];
				else f[u] += g[v][j]*max(0LL , (g[u][last] - g[v][last - 1] - sum[last - 1]));
			}
			for (int j = 0 ; j < k ; j++)
				sum[j] += g[v][j];	
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.inp","r",stdin);
	//freopen("test.out","w",stdout);
	cin >> n >> k;
	for (int i = 1 ; i <= n ; i++) {
		int x; cin >> x;
		if (x == 0) continue;
		adj[i].push_back(x);
		adj[x].push_back(i);
	}
	DFS(1 , -1);
	int ans = 0;	
	for (int i = 1 ; i <= n ; i++) {
		ans += f[i];
	}
	cout << ans;
	return 0;
}