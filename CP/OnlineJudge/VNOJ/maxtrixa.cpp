#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e3 + 7)
#pragma GCC optimize("Ofast")

int n , m;
int v[MAX_N][MAX_N];
int f[MAX_N][MAX_N];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= m ; j ++) {
			cin >> v[i][j];
		}
	}
	f[0][0] = 0;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= m ; j++) {
			f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + v[i][j];
		}
	}
	int res = INT_MIN;
	for (int a = 1 ; a <= n ; a++) {
		for (int b = 1; b <= m ; b++) {
			for (int c = a + 1; c <= n ; c++) {
				for (int d = b + 1 ; d <= m ; d++) {
					int tmp = f[c][d] - f[a - 1][d] - f[c][b - 1] + f[a - 1][b- 1];
					int u = a + 1 , v = b + 1 , x = c - 1 , y = d - 1;
					int tmp2 = f[x][y] - f[u - 1][y] - f[x][v - 1] + f[u - 1][v - 1];
					res = max(res , tmp - tmp2);
				}
			}
		}
	}
	cout << res;
	return 0;
}