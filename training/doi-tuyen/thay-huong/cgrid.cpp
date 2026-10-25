#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (307)
#define mod (int) (1e9 + 7)

int C[MAX_N][MAX_N];
int powk[MAX_N] , powk1[MAX_N] , n , k;

void init() {
	for (int i = 0 ; i < MAX_N ; i++) {
		C[i][i] = 1;
		C[i][0] = 1;
	}
	for (int i = 1 ; i < MAX_N ; i++) {
		(powk[i] = powk[i - 1]*k)%=mod;
		(powk1[i] = powk1[i - 1]*(k - 1))%=mod;
		for (int j = 1 ; j < MAX_N ; j++) {
			(C[i][j] = C[i - 1][j] + C[i - 1][j - 1]%mod) %=mod;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	init();
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 0 ; j <= n ; j++) {
			for (int h = 0 ; h <= (n - j) ; h++) {
				if (h == 0) {
					f[i + 1][j] = f[i][j]*powk1[n - j]*()
				}
				else f[i + 1][j + h] = f[i][j]*C[n - j][j]*powk[j]*powk1[n - j - h]
			}
		}
	}
	return 0;
}