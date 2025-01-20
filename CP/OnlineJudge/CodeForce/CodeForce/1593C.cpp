#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("test.inp","r",stdin);
	int t; cin >> t;
	while (t--) {
		vector<int> v;
		int n , k; cin >> n >> k;
		for (int i = 1 ; i <= k ; i++) {
			int x; cin >> x;
			v.push_back(x);
		}
		sort(v.begin() , v.end() , greater<int>());
		int ans = 0;
		int poscat = 0;
		for (auto x : v) {
			if (poscat >= x) break;
			ans++;
			poscat += n - x;
		}
		cout << ans << '\n';
	}
	return 0;
}