#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdlib.h>

using namespace std;

#pragma GCC optimize("Ofast")
#define mod (int) (1e9 + 7)
int n , m;
string N;
int dp[101][901][3];

/*void init() {
	for (int i = 0 ; i <= n ; i++) 
		for (int mul = 0 ; mul <= m ; mul++) 
			for (int status = 0 ; status <= 2 ; status ++)
				dp[i][mul][status] = 0;
}*/

void calc() {
	//init();
	for (int num = 1 ; num <= 9 ; num ++) {
		int status;
		if (num < N[0] - '0') status = 0;
		else if (num == N[0] - '0') status = 1;
		else status = 2;
		if (num <= m)
		dp[1][num][status] ++;
	}
	for (int i = 1 ; i < (int) N.size() ;i++) {
		for (int multi = 0 ; multi <= m ; multi++) 
			for (int status = 0 ; status <= 2 ; status ++) {
				if (dp[i][multi][status] == 0) continue;
				//int val = dp[i][multi][status];
				for (int num = 0 ; num <= 9 ; num ++) {
					int newstatus = status , newmulti;
					if (num + multi <= m) newmulti = num + multi;
					else continue;
					if (newstatus == 1) {
						if (num < N[i] - '0') newstatus = 0;
						else if (num > N[i] - '0') newstatus = 2;
					}
					dp[i + 1][newmulti][newstatus] = (dp[i + 1][newmulti][newstatus] + dp[i][multi][status])%mod;
				}
			}
	}
	int ans = 0;
	for (int status = 0 ; status <= 1 ; status ++) ans = (ans + dp[n][m][status])%mod;
	cout << ans; 
}

int main(){
	cin >> n >> m;
	for (int i = 0 ; i < n ; i++) N += "9"; 
	calc();
	return 0;
}