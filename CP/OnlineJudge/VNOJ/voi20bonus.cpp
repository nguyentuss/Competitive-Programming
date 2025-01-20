#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast")

int n , k;
long long f[305][305][155];
long long v[305];

int main(){
	//ios::sync_with_stdio(0); cin.tie(NULL);

	cin >> n >> k;
	for (int i = 1 ; i <= n ; i++) 
		cin >> v[i];
	for (int i = n - 1 ; i > 0 ; i--) {
		for (int j = i + 1 ; j <= n ; j ++) {
			for (int h = 1 ; h <= min(k , (j - i + 1)/2) ; h ++) { 
					f[i][j][h] = max(f[i][j][h] , f[i + 2][j][h - 1] + abs(v[i] - v[i + 1]));
					f[i][j][h] = max(f[i][j][h] , f[i][j - 2][h - 1] + abs(v[j] - v[j - 1]));
					f[i][j][h] = max(f[i][j][h] , f[i + 1][j - 1][h - 1] + abs(v[j] - v[i]));
					f[i][j][h] = max(f[i][j][h] , f[i + 1][j][h]);
					f[i][j][h] = max(f[i][j][h] , f[i][j - 1][h]);
			}
		}
	}
	
	cout << f[1][n][k];

	return 0;
}