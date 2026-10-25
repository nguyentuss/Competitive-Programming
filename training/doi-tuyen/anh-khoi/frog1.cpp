#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);


int main(){
	boost;
	int n; cin >> n;
	vector <int> v , dp(n + 1 , INT_MAX);

	int x;
	for (int i = 0 ; i < n ; i++) {
		cin >> x;
		v.push_back(x);
	}
	dp[0] = 0;
	for (int i = 0 ; i < n ; i++) {
		if (i + 1 < n) dp[i + 1] = min(dp[i + 1] , dp[i] + abs(v[i] - v[i + 1]));
		if (i + 2 < n) dp[i + 2] = min(dp[i + 2] , dp[i] + abs(v[i] - v[i + 2]));
	}
	cout << dp[n - 1];

	return 0;
}