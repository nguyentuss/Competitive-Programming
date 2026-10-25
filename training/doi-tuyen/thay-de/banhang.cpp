#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e3 + 507)
#define inf (int) (1e9 + 7)

int a[MAX_N][MAX_N];
int f[MAX_N][MAX_N];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	freopen("banhang.inp","r",stdin);
	freopen("banhang.out","w",stdout);
	int n; cin >> n;
	for (int i = 1; i <= n ; i++) {
		for (int j = 1 ; j <= n ; j++)
			cin >> a[i][j];
	}
	for (int i = 1 ; i <= n + 1; i++) {
		for (int j = 1 ; j <= n + 1; j++) {
			f[i][j] = inf;
		}
	}
	f[n + 1][n + 1] = 0;
	for (int i = n ; i >= 1 ; i--) {
		for (int j = i + 1 ; j <= n + 1 ; j++) {
			f[i][i + 1] = min(f[i][i + 1] , f[i + 1][j] + a[j][i]);
			f[i][j] = min(f[i][j] , f[i + 1][j] + a[i + 1][i]);
		}
	}
	int ans = inf;
	for (int i = 2 ; i <= n ; i++) {
		ans = min(ans , f[1][i] + a[1][i]);
	}
	cout << ans;
	return 0;
}