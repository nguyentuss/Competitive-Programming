#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast")
#define int long long
#define inf (int) (1e18)

int n;
unordered_map<int , int> m;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("test.inp","r",stdin);
	freopen("test.out","w",stdout);
	int n; cin >> n;
	m[0] = 1;
	int total = 0;
	for (int i = 1 ; i <= n ; i++) {
		int x; cin >> x;
		//map<int , int> cnt;
		for (auto it = m.begin() ; it != m.end() ; it++) {
			//cout << it->first << " ";
			if (m[it->first] && it->first <= total) m[it->first + x] = it->second;
		}
		for (auto it : m) m[it.first] += it.second;
		total += x;
	}
	int ans = inf;
	int cnte = 0;
	/*for (auto it : m) {
		if (ans > abs(total - 2*it.first) && it.second != 0) {
			cnte = it.second;
			ans = abs(total - 2*it.first);
		}
	}*/
	if (ans == 0) cout << ans << " " << cnte/2;
	else cout << ans << " " << cnte;
	return 0;
}