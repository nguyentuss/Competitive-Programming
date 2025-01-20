#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (2e5 + 7)
#define mod (int) (998244353)
#define ll long long

ll n , v[MAX_N] , fact[MAX_N];

ll solvePOW(ll a , ll x) {
	if (x == 0) return 1;
	ll child = solvePOW(a , x / 2);
	if (x % 2 == 1) 
		return ((child*child)%mod*a)%mod;
	else return (child*child)%mod;
}

ll CnK(ll n , ll k) {
	ll invfact1 = solvePOW(fact[k] , mod - 2);
	ll invfact2 = solvePOW(fact[n - k] , mod - 2);
	return (((fact[n]*invfact1)%mod*invfact2)%mod);
}

ll solve() {
	sort(v + 1 , v + 1 + n);
	if (v[n] == v[n - 1]) return fact[n];
	if (v[n] - v[n - 1] >= 2) return 0;
	int pos = n - 1;
	while (pos >= 0 && v[pos] == v[n - 1]) pos--; pos++;
	int cnt = n - pos;
	ll ans = 1;
	ans = cnt;
	for (int i = 1; i <= cnt; i++) {
		ans = ans * i % mod;
	}
	for (int i = cnt + 2; i <= n; i++) {
		ans = ans * i % mod;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	fact[0] = 1;
	for (int i = 1 ; i < MAX_N ; i++) fact[i] = (i * fact[i - 1])%mod;
	int t; cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1 ; i <= n ; i++) {
			cin >> v[i];
		}
		cout << solve() << '\n';
	}

	return 0;
}