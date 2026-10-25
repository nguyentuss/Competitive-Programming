#include <bits/stdc++.h>

using namespace std;

#define inf (int) (1e9 + 7)

int f[(1 << 20) + 7];
int a[21][21];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("donnuoc.inp","r",stdin);
	freopen("donnuoc.out","w",stdout);
	//freopen("test.inp","r",stdin);	
	//freopen("test.out","w",stdout);
	int n , k; cin >> n >> k;
	for (int i = 1 ; i <= n ;i++){
		for (int j = 1 ; j <= n ; j++) {
			cin >> a[i][j];
		}
	}
	for (int mask = 0 ; mask < (1 << n) ; mask++) {
		f[mask] = inf;
	}
	f[0] = 0;
	for (int mask = 0 ; mask < (1 << n) ; mask++) {
		if (f[mask] == inf) continue;
		for (int i = 1 ; i <= n ;i++) {
			if (!(mask & (1 << (i - 1)))) {
			for (int j = 1 ; j <= n ; j++) {
				if (i == j) continue;
				if (!(mask & (1 << (j - 1)))) {
					f[mask | (1 << (i - 1))] = min(f[mask | (1 << (i - 1))] , f[mask] + a[i][j]);
				}
			}
			}
		}
	}
	/*for (int i = 0 ; i < (1 << n) ; i++) {
		cout << i << " " << f[i] << '\n';
	}*/
	int ans = inf;
	for (int mask = 0 ; mask < (1 << n) ; mask++) {
		if (__builtin_popcount(mask) == (n - k)) {
	//		cout << mask << " " << f[mask] << '\n';
			ans = min(ans , f[mask]);
		} 
	}
	cout << ans;
	return 0;
}