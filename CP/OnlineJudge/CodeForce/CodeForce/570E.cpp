#include <bits/stdc++.h>


using namespace std;

#define mod (int) (1e9 + 7)
#define int long long

char a[507][507];
int f[2][507][507]; 
int dx1[2] = {1 , 0};
int dx2[2] = {-1 , 0};
int n , m;

bool inside(int x , int y) {
	return (x >= 1 && x <= n && y >= 1 && y <= m);
}
bool check(int x1 , int y1 , int x2 , int y2) {
	if (x1 == x2 && y1 == y2) return 1;
	if ((x1 + 1) == x2 && y1 == y2) return 1;
	if (x1 == x2 && (y1 + 1) == y2) return 1;
	return 0;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.inp","r" , stdin);
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= m ; j++) {
			cin >> a[i][j];
		}
	}
	if (a[1][1] != a[n][m]) {
		cout << 0;
		return 0;
	}
	f[0][1][n] = 1;
	int lim = (n + m - 2)/2;
	for (int k = 0 ; k <= lim ; k++) {
		int now = k & 1;
		int next = now ^ 1;
		memset(f[next] , 0 , sizeof(f[next]));
		for (int x1 = 1 ; x1 <= n ; x1++) {
			for (int x2 = 1 ; x2 <= n ; x2++) {
				if (f[now][x1][x2] == 0) continue;
				int y1 = k - x1 + 2;
				int y2 = n + m - x2 - k;
				for (int u = 0 ; u <= 1 ; u++) {
					for (int v = 0 ; v <= 1 ; v++) {
						int newx1 = x1 + dx1[u];
						int newx2 = x2 + dx2[v];
						int newy1 = k - newx1 + 3;
						int newy2 = n + m - newx2 - k - 1;
						if (newx1 <= newx2 && newy1 <= newy2 && a[newx1][newy1] == a[newx2][newy2]) {
							if (inside(newx1 , newy1) && inside(newx2 , newy2)) {
								(f[next][newx1][newx2] += f[now][x1][x2])%=mod;
								//cout << f[k + 1][newx1][newx2] << '\n';
							}
						}
					}
				} 
			}
		}
	}
	int ans = 0;
	for (int x1 = 1 ; x1 <= n ; x1++) {
		for (int x2 = 1 ; x2 <= n ; x2++) {
			int y1 = lim - x1 + 2;
			int y2 = n + m - lim - x2;
			if (!check(x1 , y1 , x2 , y2)) continue;
			(ans += f[lim&1][x1][x2])%=mod;
		}
	}
	cout << ans;
	return 0;
}