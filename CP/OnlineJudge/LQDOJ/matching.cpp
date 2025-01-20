#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_N (int) 25
#define MASK (int) 2097151
#define mod (int) (1e9 + 7)
#pragma GCC optimize("Ofast")
 
int cost[MAX_N][MAX_N];
long long dp[MAX_N][MASK] = {{0}};
int n;
 
 
bool check(int N ,int maximum) {
	int counted = __builtin_popcount(N);
	if (counted == maximum) return true;
	else return false;
}
 
void calc() {
	dp[0][0] = 1;
	for (int day = 1 ; day <= n ; day ++) {
		for (int i = 1 ; i <= n ; i ++) {
			int mask = 1 << (i - 1);
				for (int j = 0 ; j <= (1 << n) - 1 ; j ++) {
					if ((j & mask) == 0 && cost[day][i] != 0 && dp[day - 1][j] != 0) {
							if (check(j , day - 1) == true) {
							dp[day][j + mask] = (dp[day][j + mask] + dp[day - 1][j])%mod;
						}
					}
				}
		}
	} 
}
 
int main(){
	cin >> n;
	for (int i = 1 ; i <= n ; i++) 
		for (int j = 1 ; j <= n ; j++) 
			cin >> cost[i][j];
 
	calc();
	cout << dp[n][(1 << n) - 1];
	return 0;
}