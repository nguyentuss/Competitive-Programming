#include <bits/stdc++.h>

using namespace std;

#define int long long

int calc(int n) {
	int mul = 1;
	int ans = 0;
	while (n >= 5) {
		n/= 5;
		ans += n;
	}
	return ans;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("five.inp","r",stdin);
	freopen("five.out","w",stdout);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int l = 0 , r = 1e18 , ans = LLONG_MAX;
		while (l <= r) {
			int mid = (l + r)/2;
			if (calc(mid) >= n) {
				r = mid - 1;
				ans = min(ans , mid);
			}
			else l = mid + 1;
		}
		cout << ans << '\n';
	}
	return 0;
}