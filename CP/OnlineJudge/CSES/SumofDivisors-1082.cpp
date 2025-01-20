#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define mod (int) (1e9 + 7)

ll n;

ll POWER(int a , int x) {
	if (x == 0) return 1%mod;
	ll child = POWER(a , x / 2);
	if (x % 2 == 1) return (((child*child)%mod)*a)%mod;
	else return (child*child)%mod;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	ll answer = 0;
	for (ll i = 1 , j ; i <= n ;i=j) {
		ll q = n / i;
		j = n / q + 1;
		ll jump = (((j%mod)*((j - 1)%mod))%mod*POWER(2 , mod - 2)%mod)%mod;
		ll prevjump = (((i%mod)*((i - 1)%mod))%mod*POWER(2 , mod - 2)%mod)%mod;
		ll calc = (jump - prevjump + mod)%mod;
		answer = (answer + (q%mod)*calc)%mod;
	}
	cout << answer;

	return 0;
}