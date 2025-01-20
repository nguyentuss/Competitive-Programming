#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX_N (int) (1e5 + 7)
#define INF (long long) (1e18)

int n;
vector <long long> v(MAX_N);
long long dp[MAX_N][201];

void init(){
	for (int i = 1 ; i <= n; i++) v[i] = 0;
	for (int i = 0 ; i <= n; i++) 
		for (int j = 0 ; j <= 200 ;j++) 	
			dp[i][j] = INF;

	for (int i = 0 ; i <= n ; i++) dp[i][0] = 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	int t; cin >> t;
	for (int test = 1 ; test <= t ; test++) {
		cin >> n;
		init();
		for (int i = 1 ; i <= n ; i++) 
			cin >> v[i];
		for (int i = 0 ; i <= n; i++) 
			for (int j = 0 ; j <= 200 ; j++){
				if (dp[i][j] != INF) {
					dp[i + 1][j] = min(dp[i + 1][j] , dp[i][j]);
					if (dp[i][j] <= v[i + 1]*6)
						dp[i + 1][j + 1] = min(dp[i + 1][j + 1] , dp[i][j] + v[i + 1]);
				}
			}
		int ans = -1;
		for (int j = 0 ; j <= 200 ; j++)
			if (dp[n][j] != INF) ans = max(ans , j);
		cout << "Case #" << test << ": " << ans << endl; 
	}
	return 0;	
}