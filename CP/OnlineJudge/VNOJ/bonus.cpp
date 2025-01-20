#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	int n , k , x , ans = -1; cin >> n >> k;
	vector<vector<int>> f(1001 , vector <int> (1001));
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= n ; j++){
			cin >> x;
			f[i][j] = x + f[i][j - 1] + f[i - 1][j] - f[i - 1][j - 1];
			if (i >= k && j >= k) 
				ans = max(ans , f[i][j] - f[i - k][j] - f[i][j - k] + f[i - k][j - k]);
		}
	}
	cout << ans;

	return 0;
}