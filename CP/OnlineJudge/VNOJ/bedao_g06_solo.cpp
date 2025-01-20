#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e3 + 7)

int v[MAX_N];

int main() {
	ios::sync_with_stdio(0);cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n , k , p; cin >> n >> k >> p;
		int maxi = 0 , mini = INT_MAX;
		for (int i = 1 ; i <= n ; i++) {
			cin >> v[i];
			maxi = max(maxi , v[i]);
			mini = min(mini , v[i]);
		}
		if (k % 2 == 1) {
			if (p == 0) cout << maxi << '\n';
			else cout << mini << '\n';
		}
		else {
			int ans1 = 0 , ans2 = INT_MAX;
			ans1 = max(v[2] , v[n - 1]);
			ans2 = min(v[2] , v[n - 1]);
			for (int i = 2 ; i < n ; i++) {
				ans1 = max(ans1 , min(v[i - 1] , v[i + 1]));
				ans2 = min(ans2 , max(v[i - 1] , v[i + 1]));
			}
			if (p == 0) cout << ans1 << '\n';
			else cout << ans2 << '\n';
		}
	}
	return 0;
}