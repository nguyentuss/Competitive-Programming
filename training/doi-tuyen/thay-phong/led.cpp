#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);	
	int ans = 0;
	int n; cin >> n;
	if (n % 3 == 1) {
		ans = 7*(n/3 - 1);
		n = n%3 + 3;
	}
	else {
		ans = 7*(n / 3);
		n %= 3; 
	}
	if (n == 4) ans += 4;
	else if (n == 2) ans += 1;
	cout << ans;

	return 0;
}