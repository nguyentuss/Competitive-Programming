#include <bits/stdc++.h>

using namespace std;

#define inf (int) (-1e9)

int f[77][77][77][77];
int a[77][77];
int dp[77];
int v[77][77];
int ngarcute[77][77];
int tmp[77];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("test.inp","r",stdin);
	freopen("test.out","w",stdout);
	int n , m , k; cin >> n >> m >> k;
	for (int i  = 1 ; i <= n ;i ++) {
		for (int j = 1 ; j <= m ; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0 ; i <= n ; i++) {
		for (int j = 0 ; j <= m ; j++) {
			for (int num = 0 ; num <= m/2 ; num++) {
				for (int div = 0 ; div < k ; div++) {
					f[i][j][num][div] = inf;
				}
			}
		}
	}
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 0 ; j <= m ; j++) 
			f[i][j][0][0] = 0;
	}
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= m ; j++) {
			for (int num = 1 ; 2*num <= m ; num++) {
				memset(dp , 0 , sizeof dp);
				for (int div = 0 ; div < k ; div++) {
					if (f[i][j - 1][num - 1][div] == -inf) continue;
					dp[(div + a[i][j])%k] = max(dp[(div + a[i][j])%k]
					, f[i][j - 1][num - 1][div] + a[i][j]);
				}
				for (int div = 0 ; div < k ; div++) {
					if (dp[div] != 0) {
						f[i][j][num][div] = max(f[i][j][num][div] , dp[div]);
					}
				}
			}
			for (int num = 0 ; num <= m/2 ; num++)
				for (int div = 0 ; div < k ; div++) {
					f[i][j + 1][num][div] = max(f[i][j + 1][num][div] , f[i][j][num][div]);
				}
		}
	}			
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= m ; j++) {
			for (int num = 1 ; 2*num <= m ; num++) {
				for (int div = 0 ; div < k ; div++) {
					v[i][div] = max(v[i][div] , f[i][j][num][div]);
				}
			} 
		}
	}
	for (int i = 0 ; i <= n ; i++) {
		for (int div = 1 ; div < k ; div++) {
			ngarcute[i][div] = -1;
			//cout << v[i][div] << " ";
		}
		//cout << '\n';
	}
	ngarcute[0][0] = 0;
	for (int i = 1 ; i <= n ; i++) {
		for (int div = 0 ; div < k ; div++) {
			if (ngarcute[i - 1][div] == -1) continue;
			memset(tmp , 0 , sizeof tmp);
			for (int j = 0 ; j < k ; j++) {
				if (v[i][j] == 0) continue;
				tmp[(div + j)%k] = max(tmp[(div + j)%k], 
				ngarcute[i - 1][div] + v[i][j]);
				//cout << i << " " <<  div << " " << j << " " << v[i][j] << " " <<  tmp[(div + j)%k] << '\n';
			}
			for (int j = 0 ; j < k ; j++) {
				if (tmp[j] != 0) 
				ngarcute[i][j] = max(ngarcute[i][j] , tmp[j]);
			}
		}
		for (int div = 0 ; div < k ; div++) {
			ngarcute[i + 1][div] = max(ngarcute[i + 1][div] , ngarcute[i][div]);
		}
	}
	cout << ngarcute[n][0];
	return 0;
}