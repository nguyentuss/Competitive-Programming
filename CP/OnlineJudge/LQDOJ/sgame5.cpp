#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) 25
#define INF (int) -1e6
#define MASK (int) 1048577
#pragma GCC optimize("Ofast")

double cost[MAX_N][MAX_N];
double dp[MAX_N][MASK];
int n;

void init() {
	for (int i = 1 ; i <= n ; i++) 
		for (int j = 1 ; j <= n ; j++)
			dp[i][j] = INF;
}

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
					if ((j & mask) == 0 && dp[day - 1][j] != INF ) {
						if (check(j , day - 1) == true) {
							dp[day][j + mask] = max(dp[day][j + mask] , (double) (dp[day - 1][j] * ((double) cost[day][i] / 100.0)));
						}
					}
				}
		}
	} 
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	//freopen("sgame5.inp","r",stdin);
	//freopen("sgame5.out","w",stdout);
	cin >> n;
	init();
	for (int i = 1 ; i <= n ; i++) 
		for (int j = 1 ; j <= n ; j++) 
			cin >> cost[i][j];

	calc();
	cout << fixed << dp[n][(1 << n) - 1] * 100.0;
	return 0;
}