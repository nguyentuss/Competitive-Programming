#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

#pragma GCC optimize("Ofast")
#define MOD (ll) (1e9 + 7)
#define ll long long

ll n , k;

ll dp[101][100006];
vector <ll> sum(100006) , v(101);


int main(){

	cin >> n >> k;
	for (ll i = 1 ; i <= n; i++)
		cin >> v[i];

	dp[0][0] = 1;
	for (ll i = 1 ; i <= n ; i++) dp[i][0] = 1;

	for (ll i = 1 ; i <= n; i++) {
		sum[0] = 1;
		for (ll j = 1 ; j <= k; j++) 
			sum[j] = (sum[j - 1] + dp[i - 1][j])%MOD;
		for (ll j = 0 ; j <= k ; j++) {
			if (j <= v[i]) dp[i][j] = sum[j]%MOD;
			else dp[i][j] = (sum[j] - sum[j - v[i] - 1] + MOD)%MOD;
		}

	}
	cout << dp[n][k];

	return 0;
}