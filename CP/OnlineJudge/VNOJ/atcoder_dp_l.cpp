#include <bits/stdc++.h>

using namespace std;

#define MAX_N (ll) (3e3 + 7)
#define ll long long

ll n;
ll v[MAX_N] , f[MAX_N][MAX_N];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (ll i = 1 ; i <= n ;i ++) {
		cin >> v[i];
		f[i][i] = v[i];
	}
	f[0][0] = 0;
	for (ll i = n; i >= 1 ; i--) {
		for (ll j = i + 1 ; j <= n ; j++) {
			//if (f[i + 1][j] == 0 || f[i][j - 1] == 0) cout << i << " " << j << '\n';
			f[i][j] = max(v[i] - f[i+1][j] , v[j] - f[i][j - 1]);
		}
	}
	cout << f[1][n];
	return 0;
}