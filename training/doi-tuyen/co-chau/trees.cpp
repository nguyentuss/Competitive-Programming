#include <bits/stdc++.h>

using namespace std;

#define int long long

int f[50][50];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("test.inp","r",stdin);
	freopen("test.out","w",stdout);
	int n , h; cin >> n >> h;
	for (int i = 0 ; i <= n ; i++) f[0][i] = 1;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= n ; j++) {
			for (int k = 0 ; k < j ; k++) {
				if (i == 3 && j == 3) {
					cout << k << " " << j - k - 1 << " " << f[k][i - 1] << " " << f[j - k - 1][i - 1] << '\n';

				}
				f[j][i] += f[k][i - 1]*f[j - k - 1][i - 1];
			}
		}
	}
	for (int i = 1; i <= n ; i++) {
		for (int j = 1 ; j <= n ; j++) {
			cout << f[i][j] << " ";
		}
		cout << '\n';
	}
	cout << f[n][n] - f[n][h - 1];
	return 0;
}