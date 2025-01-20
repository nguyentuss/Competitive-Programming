#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (2e5 + 7)

int sum_zero[MAX_N];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("test.inp","r",stdin);
	int t; cin >> t;
	while (t--) {
		int n , k; cin >> n >> k;
		vector<int> v;
		v.push_back(2);
		for (int i = 0 ; i < n; i++) {
			int x; cin >> x;
			v.push_back(x); 
		}
		vector<int> pos_one;
		sum_zero[0] = 0;
		for (int i = 1 ; i <= n ; i++) {
			sum_zero[i] = sum_zero[i - 1] + (v[i] == 0 ? 1 : 0);
			if (v[i] == 1) pos_one.push_back(i);
		}
		int l = pos_one[0];
		int cnt = 0;
		int ans = 0;
		for (int i = 1 ; i < (int) pos_one.size() ; i++) {
			int r = pos_one[i];
			int remain = sum_zero[r] - sum_zero[l - 1];
			if (remain > k) {
				int last = sum_zero[r - 1] - sum_zero[l - 1];
				ans = max(ans , pos_one[i - 1] - l + 1 + (k - last));
				while ((sum_zero[r] - sum_zero[l - 1]) > k) {
					l = pos_one[++cnt];
				}
			}
			else {
				ans = max(ans , r - l + 1);
			}
		}
		cout << ans;
	}
	return 0;
}