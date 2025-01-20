//source:: 
#include <bits/stdc++.h>

using namespace std;

#define int long long

const int inf = 1e18 + 7;
const int N = 3e5 + 7;
const int MOD = 1e18 + 7;

int ccc = 0;

void solve() {
    int n , k; cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
    }
    vector<vector<int>> f(n + 1 , vector<int> (k + 1 , inf));
    f[0][0] = 0;
    a[0] = inf;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j <= k ; j++) {
            if (f[i][j] == inf) continue;
            f[i + 1][j] = min(f[i + 1][j] , f[i][j] + a[i + 1]);
            int mn = a[i];
            for (int h = j + 1 ; h <= k ; h++) { 
                if ((i + h - j) > n) break;
                mn = min(mn , a[i + h - j]);
                if ((i + h - j + 1) <= n) 
                    mn = min(mn , a[i + h - j + 1]);
                f[i + h - j][h] = min(f[i + h - j][h] , f[i][j] + (h - j)*mn);
            }
        }
    }
    int ans = inf;
    for (int i = 0 ; i <= k ; i++) {
        ans = min(ans , f[n][i]);       
    }
    cout << ans << '\n';
}

main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); 
	cout.tie(NULL);
	int test = 1;
	cin >> test;
	while(test--) {
		solve();
	}
	return 0;
}