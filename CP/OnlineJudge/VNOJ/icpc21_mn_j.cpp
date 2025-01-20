	#include <bits/stdc++.h>

	using namespace std;

	#define MAX_N (int) 5007
	#define inf (int) (1e9 + 7)

	char a[MAX_N][MAX_N];
	int f[MAX_N][MAX_N];
	int sz[MAX_N][MAX_N];

	int main() {
		ios_base::sync_with_stdio(0);cin.tie(NULL);
		cout.tie(NULL);
		int n , m; cin >> n >> m;
		for (int i = 1 ; i <= n ; i++) {
			for (int j = 1 ; j <= m ; j ++) {
				cin >> a[i][j];
				sz[i][j] = inf;
			}
		}
		for (int i = 1 ; i <= n ; i++) {
			for (int j = m ; j >= 1 ; j--) {
				if (a[i][j] == '1') {
					f[i][j] = f[i][j + 1] + 1;
				}
				else f[i][j] = 0;
			}
		}
		for (int i = 1 ; i <= n ; i++) {
			for (int j = 1 ; j <= m ; j++) {
				sz[i][j] = min(sz[i][j] , f[i][j]);
			}
		}
		for (int i = n ; i >= 1 ; i --) {
			for (int j = m ; j >= 1 ; j--) {
				f[i][j] = 0;
				if (a[i][j] == '1') {
					f[i][j] = f[i + 1][j] + 1;
				}
				else f[i][j] = 0;
			}
		}
		for (int i = 1 ; i <= n ; i++) {
			for (int j = 1 ; j <= m ; j++) {
				sz[i][j] = min(sz[i][j] , f[i][j]);
			}
		}
		for (int i = 1 ; i <= n ; i++) {
			for (int j = 1 ; j <= m ; j++) {
				f[i][j] = 0;
				if (a[i][j] == '1')
					f[i][j] = f[i][j - 1] + 1;
				else f[i][j] = 0;
			}
		}
		for (int i = 1 ; i <= n ; i++) {
			for (int j = 1 ; j <= m ; j++) {
				sz[i][j] = min(sz[i][j] , f[i][j]);
			}
		}
		for (int i = 1 ; i <= n ; i++) {
			for (int j = 1 ; j <= m ; j++) {
				f[i][j] = 0;
				if (a[i][j] == '1') 
					f[i][j] = f[i - 1][j] + 1;
				else f[i][j] = 0;
			} 
		}
		for (int i = 1 ; i <= n ; i++) {
			for (int j = 1 ; j <= m ; j++) {
				sz[i][j] = min(sz[i][j] , f[i][j]);
			}
		}
		int ans = 0;
		int x , y;
		for (int i = 1 ; i <= n ; i++) {
			for (int j = 1 ; j <= m ; j++) {
				if (ans < (4*(sz[i][j] - 1) + 1)) {
					ans = 4*(sz[i][j] - 1) + 1;
					x = i , y = j;
				}
			}
		}
		if (ans == 0) cout << -1;
		else {
			cout << ans << '\n';
			cout << x << " " << y;
		}
		return 0;
	}