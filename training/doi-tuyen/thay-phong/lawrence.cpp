#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e3 + 7)
#define int long long
#define inf (int) (1e9 + 7)
#pragma GCC optimize("Ofast")

int sum[MAX_N];
int a[MAX_N];
int f[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];
int n , m;

int calc(int i , int k) {
	if (i == 0) return 0;
	if (k == 0) {
		dp[i][k] = f[1][i];
		return f[1][i];
	}
	if (dp[i][k] >= 0) return dp[i][k];
	int ans = LLONG_MAX;
	for (int j = 0 ; j < i ; j++) {
		ans = min(ans , f[j + 1][i] + calc(j , k - 1));
	}
	//cout << i << " " << k << " " << ans << '\n';
	dp[i][k] = ans;
	return ans;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.inp","r",stdin);
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++) {
		cin >> a[i];
	}
	for (int i = 1 ; i <= n ;  i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	for (int l = 1 ; l <= n ; l++) {
		for (int r = 1 ; r <= n ; r++) {
			if (l >= r) f[l][r] = 0;
			else f[l][r] = f[l][r - 1] + (sum[r - 1] - sum[l - 1])*a[r];
		}
	}
	for (int i = 0 ; i <= n ;i++) {
		for (int j = 0 ; j <= m; j++) {
			dp[i][j] = -1;
		}
	}
	calc(n ,m);
	int ans = LLONG_MAX;
	for (int i = 0 ; i <= n ; i++) {
		if (dp[i][m] != -1) {
			ans = min(ans , dp[i][m]);
		}
	}
	cout << ans;


	return 0;
}