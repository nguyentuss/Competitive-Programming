#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

int dp[1005][1005];

int main() {
	boost;
	int n , m ; cin >> n >> m;

	char x;

	memset(dp,0,sizeof(dp));
	dp[0][1] = 1;
	for (int i = 1 ; i <= n ; i++) 
		for (int j = 1 ; j <= m ; j ++) {
			cin >> x;
			if (x == '#') dp[i][j] = 0;
			else dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % ((int) 1e9 + 7);
		}

	cout << dp[n][m];


	return 0;
}