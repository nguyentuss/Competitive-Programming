#include <bits/stdc++.h>

using namespace std;
string a , b;
int f[1007][1007];

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	freopen("bdxau.inp","r",stdin);
	freopen("bdxau.out","w",stdout);
	cin >> a >> b;
	int n = a.size() , m = b.size();
	a = ' ' + a , b = ' ' + b;
	for (int i = 1; i <= n ; i++) f[i][0] = i;
	for (int i = 1; i <= m ; i++) f[0][i] = i;
	for (int i = 1; i <= n ;i ++) {
		for (int j = 1 ; j <= m ; j++) {
			if (a[i] == b[j]) f[i][j] = f[i - 1][j - 1];
			else f[i][j] = min(f[i - 1][j] + 1 , min(f[i][j - 1] + 1 , f[i - 1][j - 1] + 1));
		}
	} 
	cout << f[n][m];
	return 0;
}
