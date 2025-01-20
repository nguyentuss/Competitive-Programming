#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <cmath>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define fi freopen("STMERGE.inp","r",stdin);
#define fo freopen("STMERGE.out","w",stdout);

int main() {
	boost;
	//fi;fo;

	//f[i][j][k] la chi phi nho nhat khi tao xau T trong khoang tu X[1 ... i]  va Y[1 ... j]
	// k = 0 thi ki tu cuoi la x[i] , k = 1 thi ki tu cuoi la y[i] 
	int t; cin >> t;
	while(t--){
		int m , n; cin >> m >> n;
		int F[m+3][n+3][2];
		int cost[m+3][n+3];
		for (int i = 1 ; i <= m ; i++) 
			for (int j = 1 ; j <= n ; j++) 
				cin >> cost[i][j];	
		for (int i = 1 ; i <= m ; i++) {
			F[i][0][0] = 0;
			F[i][0][1] = INT_MAX;
		}
		for (int i = 0 ; i <= n ; i++) {
			F[0][i][0] = INT_MAX;
			F[0][i][1] = 0;
		}
		for (int i = 1 ; i <= m ; i++) {
			for (int j = 1 ; j <= n ; j++) {
				F[i][j][0] = min(F[i-1][j][0],F[i-1][j][1] + cost[i][j]);
				F[i][j][1] = min(F[i][j-1][1],F[i][j-1][0] + cost[i][j]);
			}
		}
		cout << min(F[m][n][0],F[m][n][1]) << endl;
	}

	return 0;
}