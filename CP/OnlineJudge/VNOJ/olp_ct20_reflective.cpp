#include <bits/stdc++.h>

using namespace std;

#define ll long long
ll l , r;
ll POW[100];

void solvePOW() {
	POW[0] = 1;
	for (int i = 1 ; i <= 60 ; i++) {
		POW[i] = POW[i - 1]*2LL;
	}
}

ll calc(ll x) {
	ll cnt = 0 , ans = 0;
	for (int i = 60 ; i >= 1 ; i --) {
		ans += i*(x/POW[i] - cnt);
		cnt += (x/POW[i] - cnt);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	solvePOW();
	cin >> l >> r;
	cout << calc(r) - calc(l - 1);
	return 0;
}