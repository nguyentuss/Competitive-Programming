#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e7 + 7)
#define MOD (int) (1e9 +7)
#define int long long

int f[MAX_N] , sum[MAX_N] , sum_sum[MAX_N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	f[0] = 1;
	for (int i = 1 ; i < MAX_N ; i++) {
		(f[i] = f[i - 1]*i) %= MOD;
	}
	sum[0] = 1;
	for (int i = 1 ; i < MAX_N ; i++) {
		(sum[i] = sum[i - 1] + f[i])%=MOD;
	}
	sum_sum[0] = 1;
	for (int i = 1 ; i < MAX_N ; i++) {
		(sum_sum[i] = sum_sum[i - 1] + sum[i])%=MOD; 
	}
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int ans = f[n];
		ans = (ans - (sum[n - 1]*2 + 1)%MOD + MOD)%MOD;
		(ans += sum_sum[n - 2] + 2)%=MOD;
		cout << ans << '\n';
	}
	
	return 0;
}