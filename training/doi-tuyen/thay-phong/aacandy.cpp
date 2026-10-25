	#include <bits/stdc++.h>

	using namespace std;

	#define ll long long

	ll n;

	int main() {
		ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
		cin >> n;
		ll ans = 0;
		for (int k = 1 ; k <= 500000 ; k ++) {
			ll x = n - k*k + k;
			if (x%k == 0 && (x / k)%2 == 1) {
				ans ++;
				//cout << k << " " << x/k  << '\n';
			}
		}
		cout << ans;
		return 0;
	}