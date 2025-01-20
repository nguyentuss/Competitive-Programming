#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e3 + 7)
#define int long long
#define mod (int) (1e9 + 7)

int f[MAX_N][MAX_N];
int v[MAX_N];

int POW(int a , int x) {
	if (x == 0) return 1;
	int child = POW(a , x/2)%mod;
	if (x % 2 == 1) return (child*child%mod*a%mod)%mod;
	else return (child*child%mod)%mod;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.inp","r",stdin);
	int t; cin >> t;
	while (t--) {
		int n , k; cin >> n >> k;
		int total = 0;
		for (int i = 1 ; i <= n ; i++){ 
			cin >> v[i];
			total += v[i];
		}
		// f[i][j] So cach xep i ba me vao j cai ban
		for (int i = 0 ; i <= n ; i++) {
			for (int j = 0 ; j <= k ; j++) {
				f[i][j] = 0;
			}
		}
		f[0][0] = 1;
		for (int i = 0 ; i < n ; i++) {
			for (int j = 0 ; j <= k ; j++) {
				if (f[i][j] == 0) continue;
				int cur = f[i][j];
				if (j > 0) (f[i + 1][j] += (cur*j % mod)) %= mod;
				(f[i + 1][j + 1] += (cur*(k - j) % mod)%mod)%=mod; 
			}
		}
		int ans = 0;
		for (int i = 1 ; i <= k ;i++) {
			int val = f[n][i]%mod;
			(val *= POW(k - i + 1 , total)%mod) %= mod;
			(ans += val%mod)%=mod;
		}
		cout << ans%mod << '\n';
	}

	return 0;
}