#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1007)
#define inf (int) (1e9 + 7)

int a[MAX_N][MAX_N];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int n , m; cin >> n >> m;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= m ; j++) {
			int x; cin >> x;
			if (x == 1) {
				if (j == m) cout << 1;
				else cout << 1 << " ";
			}
			else {
				if (j == m) cout << " ";
				else cout << "  ";
			}
		}
		cout << '\n';
	}


	return 0;
}