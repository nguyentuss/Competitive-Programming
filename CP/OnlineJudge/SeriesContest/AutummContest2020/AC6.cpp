#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (100007)
#define inf (int) (-	1e9)

int f[MAX_N][57];
int n , m , k , d , g1 , g2 , g3;
char v[MAX_N];

void init() {
	for (int i = 0 ; i < MAX_N ; i++) {
		for (int j = 0 ; j < 57 ; j++) {
			f[i][j] = -1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	freopen("AC6.inp","r",stdin);
	freopen("AC6.out","w",stdout);
	int t; cin >> t;
	while (t--) {
		cin >> n >> m >> k >> d >> g1 >> g2 >> g3;
		for (int i = 1 ; i <= n ; i++) cin >> v[i];
		init();
		f[0][0] = 0;
		//f[1 -> n][m] = brick_2
		for (int i = 0 ; i < n ; i++) {
			for (int j = 0 ; j <= m ; j++) {
				if (f[i][j] == -1) continue;
				//don't pick
				if (i + 1 <= n) 
					f[i + 1][j] = max(f[i + 1][j] , f[i][j]);
				//pick brick_2
				if (i + 2 <= n && v[i + 1] == '.' && v[i + 2] == '.') 
					f[i + 2][j] = max(f[i + 2][j] , f[i][j] + 1);
				//pick brick_3
				if (i + 3 <= n && j + 1 <= m && v[i + 1] == '.' && v[i + 2] == '#' && v[i + 3] == '.')
					f[i + 3][j + 1] = max(f[i + 3][j + 1] , f[i][j]);
			}
		}
		int ans = inf;
		for (int j = 0 ; j <= m ; j ++) {
			if (f[n][j] == -1) break;
			for (int x = 0; x <= f[n][j]; x++) {
                // vien 1 = min(k, n - m - j * 2 - (dp[n][j] - x) * 2) * g1
                // vien 2 = (dp[n][j] - x) * g2
                // vien 3 = j * g3
                // lost = (m - j) * d
                ans = max(ans , min(k, n - m - j * 2 - (f[n][j] - x) * 2) * g1 + 
                (f[n][j] - x) * g2 + j * g3 - (m - j) * d);
            }
		}
		cout << ans << '\n';
	}

	return 0;
}