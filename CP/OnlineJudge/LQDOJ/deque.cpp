#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

long long  dp[3007][3007];

int main(){
	boost;

	long long  n; cin >> n;
	vector <long long > v(n + 1);
	for (long long  i = 1 ; i <= n; i++)
		cin >> v[i];

	for (long long  i = 0 ; i <= n ; i++) dp[i][i] = v[i];

	for (long long  i = 1 ; i <= n ; i ++)  
		for (long long  j = i - 1 ; j >= 1; j --) 
			dp[j][i] = max(v[j] - dp[j+1][i] , v[i] - dp[j][i-1]);
	cout << dp[1][n];
	for(int i = 1 ; i <= n ; i++) {
		for (int j = i - 1 ; j >= 1 ; j -- ) {
			cout << dp[j][i] << " ";
		}
		cout << '\n';
	}

	return 0;
}