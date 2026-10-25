#include <bits/stdc++.h>

using namespace std;

#define mod (int) (1e9 + 7)
#define int long long

int n , m;
char a[1007][1007];
int f[1007][1007];
int hang[1007][1007] , cot[1007][1007];;

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= m ; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1;  i <= n ; i++) {
		for (int j = 1 ; j <= m ; j++) {
			if (a[i][j] == '0') 
				hang[i][j] = j;
			else 
				hang[i][j] = hang[i][j - 1];
		}
	}
	for (int j = 1 ; j <= m ; j++) {
		for (int i = 1 ; i <= n ; i++) {
			if (a[i][j] == '0') 
				cot[j][i] = i;
			else cot[j][i] = cot[j][i - 1];
		}
	}
	f[0][1] = 1;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= m ; j++) {
			if (a[i][j] == '0')
				(f[i][j] = f[i][hang[i][j - 1]] + f[cot[j][i - 1]][j])%=mod;
			else f[i][j] = 0;
		}
	}
	cout << f[n][m]%mod;
	return 0;
}