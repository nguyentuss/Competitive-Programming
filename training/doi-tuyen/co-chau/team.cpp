#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define inf (long long) (1e18 + 7)

int a[21] , b[21] , x[21] , n;
ll ans = inf;

void write() {
	ll tich = 1 , tong = 0;
	bool kt = false;
	for (int i = 1 ; i <= n ; i++) {
		if (x[i] == 1) {
			kt = true;
			tich *= a[i];
			tong += b[i];
		}
	}
	if (kt == true)
		ans = min(ans , abs(tich - tong));
}

void quaylui(int i) {
	for (int j = 0 ; j <= 1 ; j++) {
		x[i] = j;
		if (i == n) write();
		else quaylui(i + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1 ; i <= n ; i++) {
		cin >> a[i] >> b[i];
	}
	quaylui(1);
	cout << ans;
	return 0;
}