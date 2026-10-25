#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MOD (int) (1e9 + 7)

int f[1007];
string s;
int tmp[10007];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);	
	freopen("testro.inp","r",stdin);
	freopen("testro.out","w",stdout);
	int n , m ; cin >> n >> m;
	string s; cin >> s;
	s = '0' + s;
	f[1] = 1;
	for (int i = 1 ; i <= m ; i++) {
		memset(tmp , 0 , sizeof(tmp));
		for (int j = 1 ; j <= n ; j++) {
			if (s[i] == 'R') {
				if (j - 1 <= 0) continue;
				//cout << i << " " << j << '\n';
				(tmp[j] += f[j - 1])%=MOD;
			}
			else {
				if (j + 1 > n) continue;
				(tmp[j] += f[j + 1])%=MOD;
			}
		}
		for (int j = 1 ; j <= n ; j++) {
			(f[j] += tmp[j])%=MOD;
		}
	}
	/*for (int i = 1 ; i <= m ; i++) {
		for (int j = 1 ; j <= n ; j++) {
			cout << f[i][j] << " ";
		}
		cout << '\n';
	}*/
	//for (int i = 1 ; i <= n ; i++) cout << f[i] << " ";
	cout << f[1] - 1;
	return 0;
}