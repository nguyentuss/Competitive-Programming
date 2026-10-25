#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		if (n == 1) cout << 1 << '\n';
		else {
			int ans = 1;
			while (ans*2 <= n) ans *= 2;
			int tmp = n - ans + 1;
			cout << max(tmp , ans/2) << '\n';
		}
	}

	return 0;
}