#include <bits/stdc++.h>

using namespace std;

int v[55][55];

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		long long n , m; cin >> n >> m;
		if (m > (1LL << ((long long) n - 2))) {
			cout << "IMPOSSIBLE" << '\n';
			continue;
		}
		cout << "POSSIBLE" << '\n';
		for (int i = 1 ; i <= n ; i++) {
			for (int j = 1 ; j <= n ; j++) {
				v[i][j] = 0;
			}
		}
		v[1][n] = 1;
		m--;
		for (int i = 2 ; i <= n ; i++) {
			for (int j = i + 1 ; j <= n ; j++) 
				v[i][j] = 1;
		}
		for (int i = 2 ; i < n ; i ++) {
			long long tmp = n - i - 1;
			if ((m & (1LL << tmp)) > 0) {
				v[1][i] = 1;
			}
		}
		for (int i = 1 ; i <= n ; i++) {
			for (int j = 1 ; j <= n ; j++) 
				cout << v[i][j];
			cout << '\n';
		}
	}

	return 0;
}