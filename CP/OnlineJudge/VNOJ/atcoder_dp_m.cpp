#include <bits/stdc++.h>

using namespace std;

#define mod (int) (1e9 +7)
#define MAX_N (int) (1e2 + 7)
#define MAX_K (int) (1e5 + 7)

int n , m;
int v[MAX_N];
int f[MAX_N][MAX_K];
int sum[MAX_K];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;	
	for (int i = 1 ; i <= n ; i++) {
		cin >> v[i];
		f[i][0] = 1;
	}
	f[0][0] = 1;
	for (int i = 1; i <= n ; i++) {
		sum[0] = 1;
		for (int j = 1 ; j <= m ; j++) 
			sum[j] = (sum[j - 1] + f[i - 1][j])%mod;
		for (int j = 0 ; j <= m ; j++) {
			if (j <= v[i]) (f[i][j] += sum[j])%=mod;
			else {
				f[i][j] = (sum[j] - sum[j - v[i] - 1] + mod)%mod;
			}
		}
	}
	cout << f[n][m]%mod;
	return 0;
}