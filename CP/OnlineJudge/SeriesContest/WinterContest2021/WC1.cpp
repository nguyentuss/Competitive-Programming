#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e3 + 7)

int a[MAX_N][MAX_N];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("WC1.inp","r",stdin);
	freopen("WC1.out","w",stdout);
	int t; cin >> t;
	while (t--) {
		int n , m; cin >> n >> m;
		cout << n * m << '\n';
		for (int i = 1 ; i <= n ; i++){
			for (int j = 1 ; j <= m ; j++) {
				int x; cin >> x;
				cout << i << " " << j << " " << i << " " << j << " " << x << '\n';
			}
		}
	}
	return 0;
}