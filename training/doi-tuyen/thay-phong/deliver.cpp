#include <bits/stdc++.h>

using namespace std;

#define MAX_N (ll) (1e5 + 7)
#define inf (ll) (1e9 + 7)
#define ll long long

ll n , m;
ll x[MAX_N] , a[MAX_N];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n >> m;
	for (ll i = 1 ; i <= n ; i++) {
		cin >> x[i] >> a[i];
	}
	ll last = 0  , ans = 0;
	for (ll i = n ; i >= 1 ; i--) {
		if (last != 0 && last - a[i] >= 0) {
			last -= a[i];
			continue;
		}
		if (last != 0 && last - a[i] < 0) {
			a[i] -= last;
			last = 0;
		}
		ll div = a[i]/m;
		if ((a[i] % m )!= 0) div++;
		ans += 2*x[i]*div;
		last = m*div - a[i];

		//cout << last << " " << ans << '\n';
	}
	cout << ans;
	return 0;
}