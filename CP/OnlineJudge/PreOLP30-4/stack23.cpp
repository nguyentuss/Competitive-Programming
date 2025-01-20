#include <bits/stdc++.h>

using namespace std;

int n, k , p;
int adj[51][51];
int dp[51][51];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k >> p;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= k ; j++) 
			cin >> adj[i][j];
	}
	for (int i = 1 ; i <= n; i++) 
		dp[i][0] = 0;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= k ; j++)
			dp[i][j] = dp[i][j - 1] + adj[i][j]; 
	}
	int ans = -1;
	for (int i = 0 ; i <= p ; i ++) 
		for (int j = 0 ; j <= p ; j ++) {
			int k = p - i - j;
			if (k >= 0)
			ans = max(ans , dp[1][i] + dp[2][j] + dp[3][k]);
		}
	cout << ans;

	return 0;
}