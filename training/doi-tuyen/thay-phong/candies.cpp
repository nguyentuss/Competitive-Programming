#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("candies.inp","r",stdin);
	freopen("candies.out","w",stdout);
	int n; cin >> n;
	int ans = 0;
	for (int i = 1 ; i*i <= n ; i++) {
		int j = n/i;
		int a = abs((i - 1) - (j - 1))/2;
		int b = ((i - 1) + (j - 1))/2;
		if ((a + b + 1)*(b - a + 1) == n) ans++;
	}
	cout << ans;
	return 0;
}