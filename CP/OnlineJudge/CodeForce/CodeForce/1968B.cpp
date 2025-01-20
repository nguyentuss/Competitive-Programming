//source:: 
#include <bits/stdc++.h>

using namespace std;

#define int long long

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e18 + 7;

void solve() {
	int n, m; cin >> n >> m;
	string a, b; cin >> a >> b;
	int l = 0;
	int ans = 0;
	for (auto x : a) {
		while (l < m) {
			if (b[l] == x) {
				ans++; 
				l++;
				break;
			}
			l++;
		}
	}
	cout << ans << '\n';
}

main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); 
	cout.tie(NULL);
	int test = 1;
	cin >> test;
	while(test--) {
		solve();
	}
	return 0;
}