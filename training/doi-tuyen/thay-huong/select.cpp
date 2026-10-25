#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast")

int f[21][(1<<20)+ 7];
int a[21][21];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("select.inp","r",stdin);
	freopen("select.out","w",stdout);
	int n; cin >> n;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= n ; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0 ; i <= n ; i++) {
		for (int j = 0 ; j < (1 << n) ; j++) {
			f[i][j] = INT_MIN;
		}
	}
	f[0][0] = 0;
	for (int mask = 0 ; mask < (1 << n) ; mask ++) {
		for (int i = 1 ; i <= n ; i++) {
			if (f[i - 1][mask] == INT_MIN) continue;
			for (int j = 1 ; j <= n ; j++) {
				if (!(mask & (1 << (j - 1))) && __builtin_popcount(mask) == (i - 1)) {
					f[i][mask | (1 << (j - 1))] = max(f[i][mask | (1 << (j - 1))] , f[i - 1][mask] + a[i][j]);
				}
			}
		}
	}
	cout << f[n][(1<<n) - 1];
	return 0;
}