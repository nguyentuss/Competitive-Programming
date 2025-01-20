#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (2e5 + 7)
#define int long long

int v[MAX_N];
int sum[MAX_N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("WC5.inp","r",stdin);
	freopen("WC5.out","w",stdout);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 1 ; i <= n ; i++) {
			cin >> v[i];
			sum[i] = sum[i - 1] + v[i];
		}
		int ans = 0;
		for (int i = 2 ; i <= n ;i++) {
			ans += v[i]*sum[i - 1];
		}
		cout << ans << '\n';
	}

	return 0;
}