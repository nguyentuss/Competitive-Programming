#include <bits/stdc++.h>

using namespace std;

#define MAX_N (ll) (1e3 + 7)
#define ll long long

ll sum[MAX_N];
ll a[MAX_N];
ll f[MAX_N][MAX_N];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	ll n; cin >> n;
	for (ll i = 1 ; i <= n ; i++) {
		cin >> a[i];
	}
	for (ll i = 1 ; i <= n ;  i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	for (ll l = 1 ; l <= n ; l++) {
		for (ll r = 1 ; r <= n ; r++) {
			if (l >= r) f[l][r] = 0;
			else f[l][r] = f[l][r - 1] + (sum[r - 1] - sum[l - 1])*a[r];
		}
	}
	for (ll l = 1 ; l <= n ; l++) {
		for (ll r = 1 ; r <= n ; r++) {
			cout << f[l][r] << " ";
		}
		cout << '\n';
	}

	return 0;
}