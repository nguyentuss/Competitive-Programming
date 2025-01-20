#include <bits/stdc++.h>
using namespace std;
double f[3005][3005];
double v[3005];
int main() {
	cout.precision(9);
	int n;
	cin >> n;
	double ans;
	f[0][0] = 1;
	for (int i = 1 ; i <= n ; i++) cin >> v[i];
	for (int i = 0 ; i <= n ; i++) {
		for (int j = 0 + (i == 0) ; j <= n - i ; j++) {
			double tmp = f[i - 1][j];
			if (i == 0) tmp = 0;
			f[i][j] = tmp*v[i + j] + f[i][j - 1]*(1 - v[i + j]);
		}
	}
	ans = 0;
	for(int i=n/2+1;i<=n;i++) ans+=f[i][n-i];
	cout << ans;
	return 0;
}