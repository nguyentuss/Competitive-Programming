#include <bits/stdc++.h>

using namespace std;

#define oo (int) (1e9 + 7)

vector <int> X(10007) , Y(10007);
int f[10007][10007/2];

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	int n; cin >> n;
	for (int i = 1 ; i <= n; i++) 
		cin >> X[i] >> Y[i];
	for (int i = 1 ; i <= n ; i++) {
		f[i][0] = f[i - 1][0] + Y[i];
		for (int j = 1 ; j <= ((i - 1)/2) ; j ++) 
			f[i][j] = min(f[i-1][j-1] + X[i] , f[i-1][j] + Y[i]);
		if (i % 2 == 0) 
		f[i][i/2] = f[i - 1][i / 2 - 1] + X[i];
	}
	cout << f[n][n / 2];

	return 0;
}