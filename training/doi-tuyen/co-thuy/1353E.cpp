#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e6 + 7)
#define inf (int) (1e9 + 7)

int sum[MAX_N];
int f[MAX_N][2];
// f[i] la so luong xoa toi thieu khi xet tu 1 -> i

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("test.inp","r",stdin);
	int t; cin >> t;
	while (t--) {
		int n , k; cin >> n >> k;
		for (int i = 1 ; i <= n ; i++){ 
			f[i][0] = inf;
			f[i][1] = inf;
		}
		string s; cin >> s;
		s = '0' + s;
		int cnt = 0;
		for (int i = 1 ; i <= n ; i++) {
			sum[i] = sum[i - 1] + (s[i] == '1' ? 1 : 0);
		}
		int ans = sum[n];
		for (int i = 1 ; i <= n ; i++) {
			if ((i - k) <= 0) {
				f[i][0] = inf; 
			}
			int cost = (s[i] == '0' ? 1 : 0);
			if (s[i] == '0') {
				f[i][0] = min(f[i - k][0] , f[i - k][1]) + sum[i] - sum[i - k] + 1;
				f[i][1] = sum[i - 1];
			}
			else {
				f[i][0] = sum[i - 1] + 1;
				f[i][1] = min(f[i - k][0],f[i - k][1]) + sum[i] - sum[i - k];
			}
			ans = min(ans , min(f[i][0] , f[i][1]) + sum[n] - sum[i]);
		}
		cout << ans << '\n';
	}

	return 0;
}