#include <bits/stdc++.h>

using namespace std;

#define int long long

set <int , greater<int>> s;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("timkiem.inp","r",stdin);
	freopen("timkiem.out","w",stdout);
	int n; cin >> n;
	for (int i = 1 ; i <= n ; i++) {
		int x; cin >> x;
		s.insert(x);
		auto g = s.upper_bound(x);
		if (g == s.end()) cout << -1 << endl;
		else {
			cout << *g << endl;
		}
	}

	return 0;
}