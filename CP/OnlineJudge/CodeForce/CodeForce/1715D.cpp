//source:: 
#include <bits/stdc++.h>

using namespace std;

#define int long long

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e9 + 7;

vector<pair<int , int>> adj[N];
int a[31][N];
int ans[N];

void solve() {
    int n , q; cin >> n >> q;
    while (q--) {
        int i , j , x; cin >> i >> j >> x;
        if (i > j) swap(i , j);
        for (int bit = 0 ; bit < 31 ; bit++) {
            if ((x >> bit) & 1) adj[bit].push_back({i , j});
            else a[bit][i] = a[bit][j] = 1;
        }
    }

    for (int bit = 30 ; bit >= 0 ; bit--) {
        sort(adj[bit].begin() , adj[bit].end());
        for (auto [i , j] : adj[bit]) {
            if (a[bit][j]) ans[i] |= (1 << bit);
            else if (a[bit][i]) ans[j] |= (1 << bit);
        }
        for (auto [i , j] : adj[bit]) {
            if (!((ans[i] >> bit) & 1) && !((ans[j] >> bit) & 1)) {
                ans[j] |= (1 << bit);
            }
        }
    }
    for (int i = 1 ; i <= n ; i++) cout << ans[i] << " ";
}

main() {
//    freopen("test.inp","r",stdin);
//    freopen("test.out","w",stdout);
    ios_base::sync_with_stdio(0); cin.tie(NULL);
	int test = 1;
	//cin >> test;
	while(test--) {
		solve();
	}
	return 0;
}