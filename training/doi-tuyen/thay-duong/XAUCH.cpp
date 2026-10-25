#include <iostream>
#include <algorithm>
#include <string>
#include <limits.h>
#include <fstream>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define fi freopen("XAUCH.inp","r",stdin);
#define fo freopen("XauCH.out","w",stdout);

string s1 , s2;

int dp[253][253];
int ans = INT_MIN;

int main() {
	boost;
	fi;fo;

	cin >> s1; cin >> s2;

	int m = s1.size() , n = s2.size(); 

	for (int i = 0 ; i <= m ; i++) dp[0][i] = 0;
	for (int i = 0 ; i <= n ; i++) dp[i][0] = 0;

	for (int i = 1 ; i <= m ; i++) {
		for (int j = 1 ; j <= n ; j++) {
			if (s1[i-1] != s2[j-1]) dp[i][j] = 0;
			else {
				dp[i][j] = dp[i-1][j-1] + 1;
				ans = max(ans,dp[i][j]);
			}
		}
	}

	/*for (int i = 0 ; i <= m ; i++) {
		for (int j = 0 ; j <= n ; j ++) 
			cout << dp[i][j] << " " ;
		cout << endl;
	}*/

	cout << ans;

	return 0;
}