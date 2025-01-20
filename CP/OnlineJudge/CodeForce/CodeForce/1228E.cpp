#include <bits/stdc++.h>

using namespace std;

#define mod (int) (1e9 + 7)
#define int long long

int n , K;
int f[270][270];
int C[270][270];
int powK[270];
int powk1[270];

void init() {
	for (int i = 0 ; i <= 250 ; i++) {
		C[i][i] = 1;
		C[i][0] = 1;
	}
	powK[0] = powk1[0] = 1;
	for (int i = 1 ; i <= 250 ; i++) {
		(powK[i] = powK[i - 1]*K)%=mod;
		(powk1[i] = powk1[i - 1]*(K - 1))%=mod;
		for (int j = 1 ; j < 250 ; j++) {
			(C[i][j] = C[i - 1][j] + C[i - 1][j - 1])%=mod;
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.inp","r",stdin);
	cin >> n >> K;
	init();
	f[0][0] = 1;
	for (int i = 0 ; i <= n ; i++) {
		for (int j = 0 ; j <= n ; j ++) {
			if (!f[i][j]) continue; 
			for (int k = 0 ; k <= (n - j) ; k++) {
				if (k == 0) {
					(f[i + 1][j] += f[i][j]*powk1[n - j]%mod*(powK[j] - powk1[j] + mod)%mod)%=mod;
				}
				else if ((j + k) <= n){
					(f[i + 1][j + k] += f[i][j]*C[n - j][k]%mod*powk1[n - j - k]%mod*powK[j]%mod)%=mod;
				}
			}
		}
	}
	cout << f[n][n]%mod;
	return 0;
}