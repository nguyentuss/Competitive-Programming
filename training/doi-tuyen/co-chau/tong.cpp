#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll n , k;
vector<ll> a , b;

bool isfind(ll x) {
	ll l = 0 , r = n - 1;
	while (l <= r) {
		ll mid = (l + r)/2;
		if (a[mid] > x) r = mid - 1;
		if (a[mid] < x) l = mid + 1;
		if (a[mid] == x) return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("TONG.inp","r",stdin);
	freopen("TONG.out","w",stdout);	
	cin >> n >> k;
	for (ll i = 1 ; i <= n; i++) {
		ll x; cin >> x;
		a.push_back(x);
	}
	for (ll i = 1 ; i <= n; i++) {
		ll x; cin >> x;
		b.push_back(x);
	}
	sort(a.begin() , a.end()); sort(b.begin() , b.begin());
	ll ans = 0;
	for (ll i = 0 ; i < n ; i++) {
		if (isfind(b[i])) {
			ans += abs(b[i]);
		}
	}
	if (ans >= k) cout << "WIN";
	else cout << "LOSE";
	return 0;
}