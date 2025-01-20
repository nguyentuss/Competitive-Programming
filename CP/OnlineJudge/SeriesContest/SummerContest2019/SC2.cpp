#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (3e3 + 7)

long long F[MAX_N][MAX_N];
int main() {
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t; 
	while (t--) {
		vector <int> a(3e3 + 7) , b(3e3 + 7);
		int n , m;
		cin >> n >> m;
		for (int i = 1 ; i <= n ; i++) cin >> a[i];
		for (int i = 1 ; i <= m ; i++) cin >> b[i];
		for (int i = 1 ; i <= n ;i ++) {
			for (int j = 1 ; j <= m ; j++) {
				F[i][j] = 0;
			}
		}
		for (int i = 0 ; i <= n ; i ++){
			for (int j = 0 ; j <= m ; j++) {
				if (i == 0 || j == 0) F[i][j] = 0;
				else if (a[i] == b[j]) F[i][j] = F[max(i-2 , 0)][max(j-2 , 0)] + 1;
				else F[i][j] = max(F[i-1][j],F[i][j-1]);
			}
		}
		cout << F[n][m] << '\n';
	}
	return 0;
}