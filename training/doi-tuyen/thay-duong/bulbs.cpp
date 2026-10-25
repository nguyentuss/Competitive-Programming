#include <bits/stdc++.h>

using namespace std;

#define int long long

int t , n , k;
vector<int> v;
string s;

bool check(int x) {
	int sum = 0;
	for (int mask = 1 ; mask < (1 << v.size()) ; mask++) {
		int mul = 1 , bits = 0;
		for (int i = 0 ; i < v.size() ; i++) {
			if (mask & (1 << i)) {
				bits++;
				mul *= v[i];
			}
		}
		int cur = x / mul;
		if (bits % 2 == 1) sum += cur;
		else sum -= cur;
	}
	return (sum >= k);
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("bulbs.inp","r",stdin);
	freopen("bulbs.out","w",stdout);
	cin >> t;
	while (t--) {
		v.clear();
		cin >> s >> k;
		for (int i = 0 ; i < s.size() ; i++) {
			if (s[i] == '1') v.push_back(i + 1);
		}
		int l = 1 , r = 1e18;
		int ans = 0;
		while (l <= r) {
			int mid = (l + r)/2;
			if (check(mid)) {
				r = mid - 1;
				ans = mid;
			}
			else l = mid + 1;
		}
		cout << ans << '\n';
	}

	return 0;
}