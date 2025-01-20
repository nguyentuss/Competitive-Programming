#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e3 + 7)
#define mod (int) (1e9 + 7)

char a[MAX_N][MAX_N];
int n , m;
int f[MAX_N][MAX_N];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= m ; j ++) {
			cin >> a[i][j];
		}
	}
	f[0][1] = 1;
	for (int i = 1 ; i <= n ;i++) {
		for (int j = 1 ; j <= m ; j++) {
			if (a[i][j] == '#') f[i][j] = 0;
			else (f[i][j] = f[i - 1][j] + f[i][j - 1]) %= mod;
		}
	}
	cout << f[n][m];

	return 0;
}