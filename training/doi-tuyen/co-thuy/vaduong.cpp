#include <bits/stdc++.h>

using namespace std;


#define MAX_N (int) (307)
#define MAX_M (int) (1e5 + 7)
#define inf (int) (1e16)
#define int long long

struct process {
	int l , r , c;
};

process a[MAX_M];
int f[MAX_N][MAX_N];
int cost[MAX_N][MAX_N];
int v[MAX_N];
int n , m , k;


bool cmp(process &x , process &y) {
	return x.r < y.r;
}


signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("vaduong.inp","r",stdin);
	freopen("vaduong.out","w",stdout);
	cin >> n >> m >> k;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= n ; j++) {
			cost[i][j] = inf;
		}
	}
	for (int i = 1 ; i <= m ; i++) {
		cin >> a[i].l >> a[i].r >> a[i].c;
		cost[a[i].l][a[i].r] = min(cost[a[i].l][a[i].r] , a[i].c);
	}
	for (int j = 1 ; j <= n ; j++) {
		for (int i = 2 ; i <= j ; i++){
			cost[i][j] = min(cost[i][j] , cost[i - 1][j]);
		}
	}
	/*for (int i = 1 ; i <= n ; i++) {
		for (int j = 2 ; j <= i ; j++) {
			cost[i][j] = min(cost[i][j] , cost[i - 1][j]);
		}
	}*/
	for (int i = 1 ; i <= n ; i++) 
		f[0][i] = inf;
	sort(a + 1 , a + 1 + m , cmp);
	// goi f[r][j] la dap an bai toan khi xet toi r va duoc j thang
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 0 ; j <= n ; j++) {
			f[i][j] = f[i - 1][j];
			for (int h = i - 1; h >= 0 ; h--) {
				f[i][j] = min({f[i][j] , f[h][j - (i - h)] + cost[h + 1][i]});
			}
		}
	}
	//cout << f[0][1];
	int ans = 1e16;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = k ; j <= n ; j++) {
			ans = min(ans , f[i][j]);
		}
	}
	cout << (ans == inf ? -1 : ans);
	return 0;
}