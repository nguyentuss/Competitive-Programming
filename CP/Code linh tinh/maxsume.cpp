#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e3 + 7)

long long a[MAX_N][MAX_N];
long long f[MAX_N][MAX_N];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	long long n , m; cin >> n >> m;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= m ; j++) {
			if (a[i][j] % 2 == 0) {
				f[i][j] = max(f[i - 1][j] + a[i][j] , f[i][j - 1] + a[i][j]);
			}
			else {
				f[i][j] = max(f[i - 1][j] , f[i][j - 1]);
			}
		}
	}
	cout << f[n][m];
	return 0;
}