#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int x; cin >> x;
		cout << -(x - 1) << " " << x << '\n';
	}
	return 0;
}