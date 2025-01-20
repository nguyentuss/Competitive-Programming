#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e3 + 7)
#define inf (int) (1e9 + 7)

int n , m;
int f[MAX_N][MAX_N][2];
int C[MAX_N][MAX_N];

// goi f[i][j][status] la chi phi tron nho nhat khi dung i ki tu X va j ki tu Y
// status : 0 / 1 la thang o sau la X nguoc lai la Y
// btcs : f[0][0][1] = 0 , f[0][0][0] = 0

void init() {
	for (int i = 1 ; i <= n; i++) {
		for (int j = 1 ; j <= m ; j++) {
			for (int status = 0 ; status <= 1 ; status ++) {
				f[i][j][status] = inf; 
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 1 ; i <= n ; i++) {
			for (int j = 1 ; j <= m ; j++) {
				cin >> C[i][j];
			}
		}
		init();
		for (int i = 1 ; i <= n ; i++) {
			f[i][0][0] = 0;
			f[i][0][1] = inf;
		}
		for (int i = 1 ; i <= m ; i++) {
			f[0][i][1] = 0;
			f[0][i][0] = inf;
		}
		for (int i = 1 ; i <= n ; i ++) {
			for (int j = 1 ; j <= m ; j++) {
				f[i][j][0] = min(f[i - 1][j][0] , f[i - 1][j][1] + C[i][j]);
				f[i][j][1] = min(f[i][j - 1][1] , f[i][j - 1][0] + C[i][j]);
			}
		}
		cout << min(f[n][m][0] , f[n][m][1]) << '\n';
	}

	return 0;
}