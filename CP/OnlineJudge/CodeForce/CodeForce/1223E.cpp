#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (5*1e5 + 7)
#define ii pair<int , int>
#define int long long

int n , k , f[MAX_N][2];
vector<ii> adj[MAX_N];

void DFS(int u , int father) {
	vector<int> a;
	int now = 0;
	for (int i = 0 ; i < adj[u].size() ; i++) {
		int v = adj[u][i].first;
		int val = adj[u][i].second;
		if (v != father) {
			DFS(v , u);
			now += f[v][1];
			a.push_back(f[v][0] + val - f[v][1]);
		}
	}
	sort(a.begin() , a.end() , greater<int>());
	for (int i = 0 ; i < min((int)a.size() , k) ; i++) {
		if (a[i] > 0) now += a[i];
	}
	f[u][0] = f[u][1] = now;
	if (a.size() >= k && a[k - 1] > 0) f[u][0] -= a[k - 1];
	return;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.inp","r",stdin);
	//freopen("test.out","w",stdout);
	int t; cin >> t;
	while (t--) { 
		cin >> n >> k;
		for (int i = 1 ; i <= n ; i++) {
			adj[i].clear();
			f[i][0] = f[i][1] = 0;
		}
		for (int i = 1 ; i < n ; i++) {
			int u , v , w; cin >> u >> v >> w;
			adj[u].push_back(ii(v , w));
			adj[v].push_back(ii(u , w));
		}
		DFS(1 , -1);
		int ans = 0;
		/*for (int i = 1 ; i <= n ; i ++) {
			cout << f[i][0] <<  " " << f[i][1] << '\n';
			ans = max({ans , f[i][0] , f[i][1]});		
		}
		//cout << f[1][0] << " " << f[1][1] << '\n';
		//cout << max(f[1][0] , f[1][1]);*/
		cout << max(f[1][0] , f[1][1]) << '\n';
	}
	return 0;
}