#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

unsigned long long dp[100007];
#define mod (unsigned long long) (76213)


int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	//freopen("sc2.inp","r",stdin);
	//freopen("sc2.out","w",stdout);
	dp[0] = 1 , dp[1] = 0;
	for (int i = 2 ; i <= 100000 ; i ++) {
		unsigned long long sum = (dp[i - 1]%mod + dp[i - 2]%mod)%mod;
		dp[i] = ((i - 1)%mod*sum%mod)%mod;
	}
	int x , t;
	//for (int i = 1 ; i <= t ; i++) {
		cin >> x;
		cout << dp[x] << endl; 

	return 0;
}