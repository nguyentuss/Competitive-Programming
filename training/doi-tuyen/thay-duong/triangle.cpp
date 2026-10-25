#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)
#define int long long

map<vector<int> , int> m;
vector<int> adj[MAX_N];

signed main() {	
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("triangle.inp","r",stdin);
	freopen("triangle.out","w",stdout);
	int n; cin >> n;
	for (int i = 1 ; i <= n ; i++) {
		int x , y ,z ; cin >> x >> y >> z;
		adj[i].push_back(x);
		adj[i].push_back(y);
		adj[i].push_back(z);
		sort(adj[i].begin() , adj[i].end());
		m[adj[i]] ++;
	}	
	int ans = 0;
	for (int i = 1 ; i <= n ; i++) {
		if (m[adj[i]] == 1) ans++;
	}
	cout << ans;
	return 0;
}