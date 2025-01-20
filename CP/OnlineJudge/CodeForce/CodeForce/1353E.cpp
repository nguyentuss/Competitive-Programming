#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e6 + 7)
#define inf (int) (1e9 + 7)

int sum[MAX_N];
int f[MAX_N][2];
// f[i] la so luong xoa toi thieu khi xet tu 1 -> i
// status = 1 la bien thanh 1
// status = 0 la bien thanh 0

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.inp","r",stdin);
	//freopen("test.out","w",stdout);
	int t; cin >> t;
	while (t--) {
		int n , k; cin >> n >> k;
		for (int i = 1 ; i <= n ; i++){ 
			f[i][0] = inf;
			f[i][1] = 0;
		}
		string s; cin >> s;
		s = '0' + s;
		int cnt = 0;
		for (int i = 1 ; i <= n ; i++) {
			sum[i] = sum[i - 1] + (s[i] == '1' ? 1 : 0);
		}
		if (n == 1 && sum[n] == 1) {
			cout << 0 << '\n';
			continue;
		}
		int ans = sum[n];
		for (int i = 1 ; i <= n ; i++) {
			if ((i - k) <= 0) {
				f[i][0] = inf; 
				f[i][1] = sum[i - 1];
				ans = min(ans , min(f[i][0] , f[i][1]) + sum[n] - sum[i]);
				continue;
			}
			if (s[i] == '0') {
				f[i][0] = sum[i - 1];
				f[i][1] = 1 + min(f[i - k][1] , f[i - k][0]) + sum[i - 1] - sum[i - k];
			}
			if (s[i] == '1') {
				f[i][0] = sum[i - 1] + 1;
				f[i][1] = min(f[i - k][1] , f[i - k][0]) + sum[i - 1] - sum[i - k];
			}
			//cout << i << " " << min(f[i][0] , f[i][1]) + sum[n] - sum[i] << '\n';
			ans = min(ans , min(f[i][0] , f[i][1]) + sum[n] - sum[i]);
		}
		cout << ans << '\n';
	}

	return 0;
}