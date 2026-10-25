#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (2007)
#define MAX_K (int) (3*1e5 + 7)
#define int long long

int f[MAX_N][MAX_N][2];
int v[MAX_K];


signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("phatqua.inp","r",stdin);
	freopen("phatqua.out","w",stdout);
	int n , k; cin >> n >> k;
	for (int i = 1 ; i <= n ; i++) 
		cin >> v[i];
	if (n > 2000 || k > 2000) {
		if (k == 1) {
			int sum = 0 , maxi = LLONG_MIN;
			for (int i = 1 ; i <= n ;i++) {
				sum += v[i];
				maxi = max(maxi , sum);
				if (sum < 0) {
					maxi = max(maxi , sum - v[i]);
					sum = 0;
				}
			}
			cout << maxi;
		}
		else {
			int sum = 0;
			for (int i = 1 ; i <= n ; i++) {
				if (v[i] >= 0)
				sum += v[i];
			}
			cout << sum;
		}
	}
	else {
		for (int i = 1 ; i <= n ; i++) {
			for (int j = 1 ; j <= k ; j++) {
				f[i][j][1] = max({f[i - 1][j][1] , f[i - 1][j - 1][1] , f[i - 1][j - 1][0]}) + v[i];
				f[i][j][0] = max(f[i - 1][j][1] , f[i - 1][j][0]);
			}
		}
		cout << max(f[n][k][0] , f[n][k][1]);
	}


	return 0;
}