#include <bits/stdc++.h>

using namespace std;

#define int long long

int r[17] , b[17];
char c[17];
int f_r[1<<16] , f_b[1<<16];
int f[1<<16][137];
int num_r = 0 , num_b = 0;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	for (int i = 0 ; i < n ; i++) {
		cin >> c[i] >> r[i] >> b[i];
		num_r += r[i];
		num_b += b[i];
	}
	for (int i = 0 ; i < (1 << n) ; i++) {
		for (int j = 0 ; j < 137 ; j++) {
			f[i][j] = -1;
		}
	}
	for (int i = 0 ; i < (1 << n) ; i++) {
		for (int j = 0 ; j < n ; j++) {
			if ((i >> j) & 1) {
				if (c[j] == 'R') {
					f_r[i] ++;
				}
				else f_b[i] ++;
			}
		}
	}
	f[0][0] = 0;
	for (int mask = 0 ; mask < (1 << n) ; mask++) {
		for (int j = 0 ; j < 137 ; j++) {
			if (f[mask][j] == -1) continue;
			for (int i = 0 ; i < n ; i++) {
				if ((mask >> i) & 1) continue;
				int newmask = mask | (1 << i);
				int newr = min(f_r[mask] , r[i]);
				int newb = min(f_b[mask] , b[i]);
				f[newmask][j + newr] = max(f[mask][j] + newb , f[newmask][j + newr]);
			}
		}
	}
	int ans = INT_MAX;
	for (int j = 0 ; j < 137 ; j++) {
		if (f[(1 << n) - 1][j] == -1) continue;
		ans = min(ans , max(num_r - j , num_b - f[(1 << n) - 1][j]));
	}
	cout << ans + n;
	return 0;
}