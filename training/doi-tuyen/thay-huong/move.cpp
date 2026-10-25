#include <bits/stdc++.h>

using namespace std;


#define MAX_N (int) (1e3 + 7)
#define inf (int) (1e18 + 7)
#define int long long
#pragma GCC optimize("Ofast")

int f[MAX_N][MAX_N];
int x[MAX_N] , y[MAX_N];
int dp[MAX_N][MAX_N];
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	freopen("move.inp","r",stdin);
	freopen("move.out","w",stdout);
	int n , k; cin >> n >> k;
	for (int i = 1 ; i <= n ; i++) {
		cin >> x[i] >> y[i];
	}
	for (int i = 1 ; i <= n ; i++) {
		for (int dist = 0 ; dist <= k ; dist++) {
			f[i][dist] = inf;
		}
	}
	for (int i = 1 ; i <= n ;i ++) {
		for (int j = i + 1 ; j <= n ; j++) {
			dp[j][i] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
		}
	}
	f[1][0] = 0;
	for (int i = 2 ; i <= n ; i++) {
		for (int dist = 0 ; dist <= k ; dist++) {
			for (int rev = 0 ; rev <= dist ; rev++) {
				int j = i - dist - 1 + rev;
				if (j <= 0 || f[j][rev] == inf) continue;
				//cout << i << " " << dist << " " << j << " " << rev << '\n';
				f[i][dist] = min({f[i][dist] , 
				f[j][rev] + dp[i][j]});
			}
		}
	}
	int ans = inf;
	for (int i = 0 ; i <= k ; i++) {
		ans = min(ans , f[n][i]);
	}
	cout << ans;
	return 0;
}