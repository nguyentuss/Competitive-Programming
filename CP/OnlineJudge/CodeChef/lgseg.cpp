#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 50000)
#define int long long

int sum[MAX_N];
int f[MAX_N][20];
int v[MAX_N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.inp","r",stdin);
	int t; cin >> t;
	while (t--) {
		int n , k , s; cin >> n >> k >> s;
		sum[0] = 0;
		for (int i = 1 ; i <= n ;i++) {
			cin >> v[i];
			sum[i] = sum[i - 1] + v[i];
		}
		for (int i = 1 ; i <= n ;i++) {
			for (int j = 0 ; j <= 19 ; j++) {
				f[i][j] = 0;
			}
		}
		for (int i = 1 ; i <= n ; i ++) {
			int l = 1 , r = i;
			int pos = -1;
			while (l <= r) {
				int mid = (l + r)/2;
				if (sum[i] - sum[mid - 1] <= s) {
					pos = mid;
					r = mid - 1;
				}
				else {
					l = mid + 1;
				}
			}
			if (pos != -1) {
				f[i][0] = pos;
			}
			//f[i][0] = lower_bound(sum + 1 , sum + 1 + i , sum[i] + s) - sum;
		}
		for (int j = 1 ; j <= 19 ; j ++) {
			for (int i = 1 ; i <= n ; i++) {
				if ((f[i][j - 1] - 1) > 0)
					f[i][j] = f[f[i][j - 1] - 1][j - 1];
			}
		}
		int ans = 0;
		for (int i = 1 ; i <= n ;i++) {
			int id = i + 1 , tmp = k;
			for (int j = 19 ; j >= 0 ; j--) {
				if (tmp >= (1 << j) && f[id - 1][j] != -1){
					id = f[id - 1][j];
					tmp -= (1 << j);
				}
			}
			//cout << id;
			ans = max(ans , i - id + 1);
		}
		cout << ans << '\n';
	}
	return 0;
}