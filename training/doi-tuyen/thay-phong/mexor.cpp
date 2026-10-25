#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast")

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		if (n == 0) cout << 1 << '\n';
		else if (n == 1) cout << 2 << '\n';
		else {
			int ans = 1;
			while (ans*2 <= n) ans *= 2;
			cout << ans << '\n';
		}
	}

	return 0;
}