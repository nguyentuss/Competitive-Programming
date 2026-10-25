#include <bits/stdc++.h>

using namespace std;

int n , m;
int F[107][107];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("mrect.inp","r",stdin);
	//freopen("mrect.out","w",stdout);
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= m ; j++) {
			int x;
			cin >> x;
			F[i][j] = x + F[i - 1][j] + F[i][j - 1] - F[i - 1][j - 1];
		}
	}
	int ans = INT_MIN;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= m ; j++) {
			for (int x = 1 ; x <= i ; x++) {
				for (int y = 1 ; y <= j ; y++) {
					ans = max(ans , F[i][j] - F[i - x][j] - F[i][j - y] + F[i - x][j - y]);
				}
			}
		}
	}
	cout << ans;
	return 0;
}