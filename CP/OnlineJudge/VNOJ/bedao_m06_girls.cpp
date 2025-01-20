#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll m , n , k;
vector<ll> v;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> m >> n >> k;
	for (ll i = 0 ; i < m ;i++) {
		ll x; cin >> x;
		v.push_back(x);
	}
	sort(v.begin() , v.end());
	ll ans = 0;
	for (int i = 0 ; i < n ; i++) {
		ans += v[i];
	}
	int l = 0 , r = n - 1;
	ll total = ans;
	if (v[n - 1] - v[0] > k) ans = -1;
	while (r < m - 1) {
		r++ , l++;
		total -= v[l - 1] , total += v[r];
		if (v[r] - v[l] <= k) {
			ans = max(ans , total);
		}
	}
	if (ans != -1) return (cout << ans , 0);
	return (cout << -2 , 0);
}