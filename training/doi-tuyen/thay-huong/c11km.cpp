#include <bits/stdc++.h>

using namespace std;

#define oo (int) (1e9 + 7)

vector <int> v(10000);
int x;
int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	int n ;cin >> n;
	for (int i = 1 ; i <= n ; i ++) {
		cin >> v[i];
	}
	vector <vector <int>> f(3000 , vector <int>(3000 , oo));
	f[0][0] = 0;
	for (int i = 1;  i <= n ; i++) {
		for (int j = 0 ; j <= n ; j ++) {
			if (v[i] > 100 && j > 0) {
				f[i][j] = min(f[i - 1][j + 1] , f[i - 1][j - 1] + v[i]);
			}
			else {
				f[i][j] = min(f[i - 1][j + 1] , f[i - 1][j] + v[i]);
			}
		}
	}
	int ans = oo;

	for (int i = 0 ; i <= n ; i++) 
		ans = min(ans , f[n][i]);

	cout << ans;
	return 0;
}