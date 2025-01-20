#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;


#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define INF (int) 1e9

int main(){
	boost;


	int n; cin >> n;
	int a[n + 3];

	for (int i = 1 ; i <= n; i++) cin >> a[i];

	int dp[n + 3][2];
	for (int i = 1 ; i <= n; i++) {
		dp[i][0] = -INF;
		dp[i][1] = -INF;
	}	
	dp[1][1] = a[1];
	int max1 = -INF , max2 = -INF;
	for (int i = 2 ; i <= n ; i++) {
			max1 = max(max1,dp[i - 1][1]);
			max2 = max(max2,dp[i - 1][0]);
			dp[i][1] = max(dp[i][1] , max(max2 + a[i] , a[i]));
			dp[i][0] = max(dp[i][0] , max1 - a[i]);
	}

	int ans = -INF;
	for (int i = 1 ; i <= n; i++)
		ans = max(ans , max(dp[i][0] , dp[i][1]));
	cout << ans; 

	return 0;
}