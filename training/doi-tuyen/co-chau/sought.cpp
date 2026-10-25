#include <bits/stdc++.h>

using namespace std;

#define int long long

map<int , int> m;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("sought.inp","r",stdin);
	freopen("sought.out","w",stdout);
	int n , k; cin >> n >> k;
	int ans = 0;
	for (int i = 1 ; i <= n ; i++) {
		int a , b , c; cin >> a >> b >> c;
		if ((k - a)%b == 0) {
			m[(k - a)/b + 1] += c;
			ans += c;
		}
	}
	int maxi = 0;
	for (auto it : m) {
		maxi = max(maxi , it.second);
	}
	cout << ans << " " << maxi;

	return 0;
}