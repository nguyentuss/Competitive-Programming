#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
long long a[5007],b[5007];
long long f[5007][5007];

int main() {
	boost;

	int n,w ; cin >> n >> w;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 0 ; j <= w ; j++) {
			f[i][j] = 0;
		}
	}

	for (int i = 1 ; i <= n; i++) 
		cin >> a[i] >> b[i];

	for (int i = 1 ; i <= n ;i ++) f[0][i] = 0;

	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= w ; j ++) {
			if (a[i] > j) f[i][j] = f[i-1][j];
			else f[i][j] = max(f[i-1][j],f[i-1][j-a[i]] + b[i]);
		}
	}
	cout << f[n][w];

	return 0;
}