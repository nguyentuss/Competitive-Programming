#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	ll n; cin >>n;
	ll x = 1LL, ans = 0LL;
	while (n) {
		ans += (n%2)*x;
		x *= 3;
		n /= 2;
	}
	cout << ans;
	return 0;
}