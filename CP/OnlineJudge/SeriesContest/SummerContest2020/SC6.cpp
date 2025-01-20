#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD (int) (1e9 + 7)

int n , p , cntw , cntb;
ll f[31][31][31][31];
ll C[31][31];
ll sumeven[31] , sumodd[31];
ll POW[31];
ll status[31];

void solve() {
	C[0][0] = 1;
	POW[0] = 1;
	for (int i = 1 ; i <= 30 ; i++) {
		POW[i] = (POW[i - 1]*2)%MOD;
		C[i][i] = 1;
		C[i][0] = 1;
	}
	for (int i = 1 ; i <= 30 ; i++) {
		for (int j = 1 ; j <= i ; j++) {
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1])%MOD;
		}
	}
	for (int i = 0 ; i <= 30 ; i++) {
		for (int j = 0 ; j <= i ; j++) {
			if (j % 2 == 0) 
				(sumeven[i] += C[i][j]) %= MOD;
			else 
				(sumodd[i] += C[i][j]) %= MOD; 
		}
	}
}

void init() {
	cntw = cntb = 0;
	for (int i = 0 ; i <= n ; i++) {
		for (int ow = 0 ; ow <= n ; ow++) {
			for (int ew = 0 ; ew <= n ; ew++) {
				for (int eb = 0 ; eb <= n ; eb ++) {
					f[i][ow][ew][eb] = 0;
				}
			}
		}
	}
}

void DynamicProgramming(){
	f[0][0][0][0] = 1;
	for (int i = 0 ; i < n ; i++) {
		for (int ow = 0 ; ow <= i ; ow++) {
			for (int ew = 0 ; ow + ew <= i ; ew++) {
				for (int eb = 0 ; eb <= i ; eb++) {
					if (f[i][ow][ew][eb] == 0) continue;
					int ob = i - ow - ew - eb;
					ll val = f[i][ow][ew][eb];
					if (status[i + 1] == 0) {
						(f[i + 1][ow + 1][ew][eb] += ((val*POW[ew + ow + eb])%MOD*sumeven[ob])%MOD) %= MOD;
						(f[i + 1][ow][ew + 1][eb] += ((val*POW[ew + ow + eb])%MOD*sumodd[ob])%MOD) %= MOD;
					}
					if (status[i + 1] == 1) {
						(f[i + 1][ow][ew][eb] += ((val*POW[eb + ob + ew])%MOD*sumeven[ow])%MOD) %= MOD;
						(f[i + 1][ow][ew][eb + 1] += ((val*POW[eb + ob + ew])%MOD*sumodd[ow]%MOD)) %= MOD;
					}
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("inp.inp","r",stdin);
	//freopen("out.out","w",stdout);
	solve();
	int t; cin >> t;
	while (t--) {
		cin >> n >> p;
		init();
		for (int i = 1 ; i <= n ; i++) {
			cin >> status[i];
		}
		DynamicProgramming();
		ll ans = 0;
		for (int ow = 0 ; ow <= n ; ow++) {
			for (int ew = 0 ; ew + ow <= n ; ew++) {
				for (int eb = 0 ; eb <= n ; eb++) {
					int ob = n - ow - ew - eb;
					if (ob < 0) continue;
					if ((ow + ob)%2 == p) {
						//cout << n << " " << ow << " " << ew << " " << ob << " " << eb << '\n';
						//cout << f[n][ow][ew][eb] << '\n';
						(ans += f[n][ow][ew][eb])%=MOD;
					}
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}