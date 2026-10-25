#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("soganhh.inp","r",stdin);
	freopen("soganhh.out","w",stdout);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int ans = 0;
		for (int i = 1 ; i * i <= n ; i++) {
			if (n % i == 0) {
				if ((n / i) == i) {
					ans += i;
				}
				else {
					ans += (n/i) + i;
				}
			}
		}
		if (2*n <= ans) cout << 1 << '\n';
		else cout << 0 << '\n';
	}

	return 0;
}