#include <bits/stdc++.h>

using namespace std;

#define ii pair <int ,int>

char v[50][50];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n , m; cin >> n >> m;
		for (int i = 1 ; i <= n ; i++) {
			for (int j = 1 ; j <= m; j++) {
				cin >> v[i][j];
			}
		}
		for (int i = 1 ; i <= n ;i++) {
			for (int j = 1 ; j <= m ;j++) {
				int tmp = j - 1;
				if (v[i][j] != '?') {
					while (v[i][tmp] == '?') {
						v[i][tmp] = v[i][j];
						tmp--;
					}
					tmp = j + 1;
					while (v[i][tmp] == '?') {
						v[i][tmp] = v[i][j];
						tmp ++;
					}

				}
			}
		}
		for (int i = 1 ; i <= n ; i++) {
			for (int j = 1 ; j <= m ; j++) {
				int tmp = i - 1;
				if (v[i][j] != '?') {
					while (v[tmp][j] == '?') {
						v[tmp][j] = v[i][j];
						tmp --;
					}
					tmp = i + 1;
					while (v[tmp][j] == '?') {
						v[tmp][j] = v[i][j];
						tmp ++;
					}
				}
			}
		}
		for (int i = 1 ; i <= n ; i++) {
			for (int j = 1 ; j <= m; j ++) {
				cout << v[i][j] ;
			}
			cout << '\n';
		}
	}
	return 0;
}