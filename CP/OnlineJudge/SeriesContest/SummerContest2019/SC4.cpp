#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)

int n , m;
int f[200][200][200];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		for (int i = 0 ; i <= 199 ; i++) {
			for (int j = 0 ; j <= 199 ; j++) {
				for (int k = 0 ; k <= 199 ; k++) {
					f[i][j][k] = 0;
				}
			}
		}
		cin >> n >> m;
		f[0][0][0] = 0;
		for (int i = 1 ; i <= n ; i ++) {
			for (int b = i ; b >= 0 ; b--) {
				for (int a = 0 ; a <= b ; a++) {
					if (b == i) f[i][a][b] = f[a][0][0];
					else 
						for (int x = 1 ; x <= min(i - b , m) ; x ++) {
							f[i][a][b] = max(f[i][a][b] , i - f[i][b - a][b + x]);
						}
				}
			}
		}
		cout << f[n][0][0] << '\n';
	}

	return 0;
}