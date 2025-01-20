#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <limits.h>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
const int INF = (int) 1e9 + 7;

int f[50][50][55];

int main() {
	boost;
	memset(f,0,sizeof(f));

	for (int i = 1 ; i <= 30 ; i ++) {
		for (int j = 1 ; j <= 30 ;j++) {
			for (int x = 1 ; x <= 50 ; x ++) {
				if (x == i * j) continue;
				f[i][j][x] = INF; 
				for (int x1 = 0 ; x1 <= x ; x1 ++){
					for (int j1 = 1 ; j1 <= j - 1 ; j1 ++) 
						f[i][j][x] = min(f[i][j][x],f[i][j1][x1] + f[i][j-j1][x-x1] + i*i);
					for (int i1 = 1 ; i1 <= i - 1 ; i1 ++) 
						f[i][j][x] = min(f[i][j][x],f[i1][j][x1] + f[i - i1][j][x - x1] + j*j);
					}
				}
			}
	}
	int t; cin >> t;
	while (t --){
		int n , m , k ; cin >> n >> m >> k;
		cout << f[n][m][k] << endl;
	}

	return 0;
}