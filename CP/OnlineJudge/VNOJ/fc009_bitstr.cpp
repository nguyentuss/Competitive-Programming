#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)
#define mod (unsigned long long) (1000007)

unsigned long long f[MAX_N][107];
unsigned long long POW[MAX_N];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int n , k; cin >> n >> k;
	if (k > n) cout << 0;
	else {
		for (int i = 0 ; i <= k ; i++) {
			f[i][i] = 1LL;
		}
		POW[0] = 1LL;
		for (int i = 1 ; i <= n ;i ++) {
			POW[i] = (POW[i - 1]%mod*2LL%mod)%mod;
		}
		for (int i = 0 ; i <= n ;i++) {
			for (int j = 0 ; j <= k ; j++) {
				if (j > i || f[i][j] == 0) continue;
				f[i + 1][j] = (((2LL*f[i][j])%mod + POW[i - j]%mod)%mod - f[i - j][j]%mod + mod)%mod;
			}	
		}
		cout << f[n][k]%mod;
	}
	return 0;
}