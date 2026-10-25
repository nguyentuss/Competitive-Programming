#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e6 + 7)

vector<int> v;
int cnt[MAX_N];

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	/*int t; cin >> t;
	while(t--) {
		memset(cnt , 0 , sizeof cnt);
		v.clear();
		int n , k; cin >> n >> k;
		for (int i = 0 ; i < n ; i++) {
			int x; cin >> x;
			v.push_back(x);
		}
		int ans = 0;
		for (auto e : v) {
			ans += cnt[k - e];
			cnt[e] ++;
		}
		cout << ans << '\n';
	}*/

	cout << 4 + 2 % 3;

	return 0;
}