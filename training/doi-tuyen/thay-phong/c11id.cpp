#include <bits/stdc++.h>

using namespace std;

#define mod (int) (1e9 + 7)
#define ll long long

ll n; 
vector<ll> v;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0 ; i < n ; i++) {
		ll x; cin >> x;
		v.push_back(x);
	}
	sort(v.begin() , v.end());

	ll ans = 1 , cnt = 0;
	for (int i = 0 ; i < n ; i++) {
		ans = (ans*(v[i] - cnt)%mod)%mod;
		cnt ++;
	}
	cout << ans;
	return 0;
}