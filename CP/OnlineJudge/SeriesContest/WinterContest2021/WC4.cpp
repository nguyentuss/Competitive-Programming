#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MAX_N (int) (1e3 + 7)
#define mod (int) (1e9 + 7)

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("WC4.inp","r",stdin);
	freopen("WC4.out","w",stdout);
	int t; cin >> t;
	while (t--) {
		string a , b , s; cin >> a >> b >> s;
		int n = a.size();
		int sum = 1;
		for (int i = 1 ; i <= n ; i++) {
			(sum *= 25) %= mod;
		}
		cout << sum << '\n';
	}

	return 0;
}