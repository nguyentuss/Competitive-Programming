#include <bits/stdc++.h>

using namespace std;

#define inf (int) (1e9 + 7)

int f[20][(1 << 16) + 7];
int a[20][20];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("dulich.inp","r",stdin);
	freopen("dulich.out","w",stdout);
	int n, m; cin >> n;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= n ; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1 ; i <= n ; i++) {
		for (int mask = 0 ; mask < (1 << n) ; mask++) {
			f[i][mask] = inf;
		}
	}
	for (int i = 1 ; i <= n ;i++) 
		f[i][(1<<(i -1))] = 0;
	for (int mask = 0 ; mask < (1 << n) ; mask++) {
		for (int i = 1 ; i <= n ; i++) {
			if (f[i][mask] == inf) continue;
			for (int j = 1 ; j <= n ; j++) {
				if (!(mask & (1 << (j - 1)))) {
					f[j][mask | (1 << (j - 1))] = min(f[j][mask | (1 << (j - 1))] , f[i][mask] + a[i][j]);
				}
			}
		}
	}
	int ans = inf;
	for (int i = 1 ; i <= n ;i++) {
		ans = min(ans , f[i][(1 << n) - 1]);
	}
	cout << ans;
	return 0;
}