#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define int long long

int v[450] , sum[450][450] = {0};
int dp[450][450] ;

signed main() {
	boost;
	//fi;fo;

	int n; cin >> n;

	for (int i = 1 ; i <= n ; i ++) cin >> v[i];


	for (int i = 1 ; i <= n ; i++) 
		for (int j = i ; j <= n ; j++) 
			sum[i][j] = sum[i][j-1] + v[j];

	for (int i = n ; i >= 1 ; i --){
		for (int j = i + 1 ; j <= n; j ++) {
			if (i == j) dp[i][j] = 0;
			else {
				dp[i][j] = dp[i][i] + dp[i + 1][j] + sum[i][j];
				for (int k = i+1 ; k <= j ; k ++) {
					dp[i][j] = min(dp[i][j],dp[i][k] + dp[k+1][j] + sum[i][j]);
					//cout << dp[i][j] << endl;
				}
			}
		}
	}

	/*for (int i = 0 ; i <= n ; i ++) {
		for (int j = 0 ; j <= n ; j ++) 
			cout << dp[i][j] << " " ;
		cout << endl;
	}*/

	
	cout << dp[1][n];


	return 0;
}