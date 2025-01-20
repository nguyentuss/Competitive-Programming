#include <bits/stdc++.h>

using namespace std;

int F[2007][2007];

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	string a , b; cin >> a >> b;
	int k ; cin >> k;
	int n = a.size() , m = b.size();
	a = ' ' + a;
	b = ' ' + b;
	for (int i = 0 ; i <= n ; i ++) F[i][0] = k * i;
	for (int i = 0 ; i <= m ; i ++) F[0][i] = k * i;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= m ; j++) {
			F[i][j] = min(F[i - 1][j] + k , min(F[i][j - 1] + k , F[i - 1][j - 1] + abs(abs(a[i] - 'a') - abs(b[j] - 'a'))));
		}
	}
	cout << F[n][m];
	return 0;
}