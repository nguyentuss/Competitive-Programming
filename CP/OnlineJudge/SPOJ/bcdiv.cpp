#include <bits/stdc++.h>

using namespace std;

int F[1000][1000];

int main() {

	int n , k ; cin >> n >> k;
	F[0][0] = 1;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= k ;j ++) {
			F[i][j] = F[i - 1][j - 1] + F[i -1][j]*j;
		}
	}
	cout << F[n][k];
	return 0;
}