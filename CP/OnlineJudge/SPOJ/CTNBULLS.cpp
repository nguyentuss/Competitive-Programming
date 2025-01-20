#include <bits/stdc++.h>

using namespace std;

vector <long long> dp(100007);

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);

	int n , k ; cin >> n >> k;

	dp[0] = 1;
	for (int i = 1 ; i <= n ; i++)
		if (i <= k + 1) dp[i] = (i%2111992 + 1)%2111992;
		else dp[i] = (dp[i - 1]%2111992 + dp[i - k - 1]%2111992)%2111992;

	cout << dp[n];
	return 0;
}