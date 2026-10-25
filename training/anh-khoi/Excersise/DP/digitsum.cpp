#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

#define modulo (long long) (1e9 + 7)

string N;
int d;
long long dp[10007][901][3];

void solve() {
	int len = N.size();
	for (int num = 1 ; num <= 9 ; num++) {
		int status;
		if (num < N[0] - '0') status = 0;
		else if (num == N[0] - '0') status = 1;
		else status = 2;
		if (num <= m) 
			dp[1][num][status] ++;
	}
	for (int i = 1 ; i < len ; i ++) {
		for (int multi = 0 ; multi < d ; multi++){
			for (int status = 0 ; status < 3 ; status ++) {
				if (dp[i][multi][status] == 0) 
					continue;
				for (int num = 0 ; num <= 9 ; num ++) {
					int newstatus = status;
					int multi;
					if (multi + num <= m) newmulti = multi + num;
					if (status == 1) {
						if (num < N[i] - '0') newstatus = 0;
						else if (num > N[i] - '0') newstatus = 2;
					}
					dp[i + 1][newmulti][newstatus] = (dp[i + 1][newmulti][newstatus] + dp[i][multi][status])%modulo;
				}
			}
		}
	}
	long long ans = 0;
	cout << dp[2][0][0];
	for (int i = 1 ; i <= len ; i++) 
		for (int status = 0 ; status <= (i < len ? 2 : 1) ; status ++) {
			ans = (ans%modulo + dp[i][0][status]%modulo)%modulo;
		}

	cout << ans%modulo;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);

	cin >> N >> d;
	solve();

	return 0;
}