#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (100)

int v[MAX_N];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.inp","r",stdin);
	//freopen("test.out","w",stdout);
	int t; cin >> t;
	while (t--) {
		map<int , int> similar;
		int n; cin >> n;
		bool found = false;
		for (int i = 1 ; i <= n ; i++) {
			cin >> v[i];
			similar[v[i]] ++;
			if (similar[v[i]] >= (n / 2)) found = true;
		}
		if (found) {
			cout << -1 << '\n';
			continue;
		}
		sort(v + 1 , v + 1 + n);
		int res = 0;
		for (int i = 1 ; i <= n ; i ++) {
			map<int ,int> cnt;
			for (int j = i + 1 ; j <= n ; j++) {
				int last = v[j] - v[i];
				for (int k = 1 ; k * k <= last ; k ++) {
					if (last % k == 0) {
						cnt[k]++;
						if (last/k != k) {
							cnt[last/k]++;
						}
					}
				}
			}
			int limit = n/2;
			for (auto x : cnt) {
				if (x.second >= (limit - similar[v[i]])) {
					res = max(res , x.first);
				}	
			}
		}
		cout << res << '\n';
	}
	return 0;
}