#include <bits/stdc++.h>

using namespace std;

struct pos {
	int l , m;
};

int f[51][2507] , g[51][2507];
vector <pos> val(51);
vector <int> v(51);
int n , m;

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;            
	for (int i = 1 ; i <= n ; i++) 
		cin >> v[i];
	cin >> m;
	int x , y;
	for (int i = 1 ; i<= m ; i++) {
		cin >> x >> y;
		val[i].l = x , val[i].m = y;
	}
	// g[i][j] gia tri lon nhat khi i cat j lan
	// f[i][j] gia tri lon nhat khi xet 1 -> i va cat tong cong j lan
	for (int i = 1 ; i <= 50 ; i++) g[val[i].l][0] = max(g[val[i].l][0] , val[i].m);
	for (int i = 1 ; i <= 50 ; i++) {
		for (int j = 1 ; j <= 50 ; j++) {
			for (int k = 1 ; k <= m ; k++) {
				if (i >= val[k].l)
				g[i][j] = max(g[i][j] , g[i - val[k].l][j - 1] + val[k].m);
			}
		}
	}
	for (int i = 1 ; i <= n; i++) {
		for (int j = 0 ; j <= 500 ; j++) 
			for (int k = 0 ; k < v[i] && k <= j ; k++) 
				f[i][j] = max(f[i][j] , f[i - 1][j - k] + g[v[i]][k]);
	}
	int ans = 0;
	for (int i = 0 ; i <= 100 ; i++) {
		//cout << f[n][i] << " ";
		ans = max(ans , f[n][i] - i*(i + 1)/2);
	}
	cout << ans;


	return 0;
}