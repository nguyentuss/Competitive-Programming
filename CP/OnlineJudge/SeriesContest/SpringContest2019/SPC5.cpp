#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1005)
#define MOD (int) (1e9 + 7)
int C[MAX_N][MAX_N] , dp[MAX_N][MAX_N][2][2] , cnt[MAX_N];
int n , k;

//dp[i][j][x][y] la so cach ma i phan tu co j vi tri tot , x : 0/1 la co phan tu i hay chua , 
//y : 0/1 la co phan tu i + 1 hay chua


void init() {
	for (int i = 0 ; i < MAX_N ; i++) {
		C[i][i] = 1;
		C[i][0] = 1;
	}
	for (int i = 1 ; i < MAX_N ; i++) {
		for (int j = 1 ; j < i ; j++) {
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1])%MOD;
		}
	}
	return;
}

void calc() {
	dp[0][0][1][0] = 1;
	for (int i = 0 ; i < n ; i++) {
		for (int j = 0 ; j <= i ; j++) {
			for (int x = 0 ; x <= 1 ; x++) {
				for (int y = 0 ; y <= 1 ; y++) {
					if (dp[i][j][x][y] == 0) continue;
					(dp[i + 1][j][y][0] += dp[i][j][x][y]) %= MOD;
					if (x == 0)
						(dp[i + 1][j + 1][y][0] += dp[i][j][x][y]) %= MOD;
					if (i + 2 <= n) 
						(dp[i + 1][j + 1][y][1] += dp[i][j][x][y]) %= MOD;
				}
			}
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	init();
	int t; cin >> t;
	while (t--) {
	 	cin >> n >> k;
	 	memset(dp, 0, sizeof(dp)); 
    	memset(cnt, 0, sizeof(cnt));
		calc();
		for (int i = 0 ; i <= n ; i++) {
			for (int x = 0 ; x <= 1 ; x ++) {
				for (int y = 0 ; y <= 1 ; y++) {
					(cnt[i] += dp[n][i][x][y]) %= MOD;
				}
			}
		}
		for (int i = 0 ; i <= n ; i++) {
			for (int j = 1 ; j <= n - i ; j ++) {
				cnt[i] = (1LL * cnt[i] * j)%MOD;
			}
		}

		for (int i = n - 1 ; i >= 0 ; i--) {
			for (int j = i + 1 ; j <= n ; j++) {
				cnt[i] = (cnt[i] - (1LL * C[j][j - i] * cnt[j])%MOD + MOD)%MOD;
			}
		}
		cout << cnt[k] << '\n';
	}
	return 0;
}