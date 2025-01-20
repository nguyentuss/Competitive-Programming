#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

vector <int> v;
int x , n;
vector <int> dp(1001,INT_MIN);

void init() {
	for (int i = 1 ; i <= n; i++) 
		dp[i] = 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cin >> n;
	for (int i = 0 ; i < n ; i++) {
		cin >> x;
		v.push_back(x);
	}
	long long ans = 0;
	while (dp[n] != 0) {
		init();
		dp[1] = v[0];
		for (int i = 1 ; i <= n; i++) {
			for (int j = i + 1 ; j <= i + 2 ; j ++) 
				dp[j] = max(dp[j] , min(v[j - 1] , dp[i]));
		}
		//if (dp[n] == 0) break;
		for (int i = 0 ; i < n ; i++) v[i] = max(0 , v[i] - dp[n]);
		ans += dp[n];
	}
	cout << ans;

	return 0;
}