#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

#define mod (long long) (1e9 + 7)
#define MAX_L 2003

string a , b;
int m , d;
int dp[2003][2003][3];

void init(){
	for (int i = 0 ; i < MAX_L ; i++) 
		for (int r = 0 ; r < m ; r++)  
				for (int status = 0 ; status < 3 ; status ++) 
					dp[i][r][status] = 0;
}

void solve(){
	int len = a.size();
	if (a[len - 1] == '0') {
		for (int i = len - 1 ; i >= 0 ; i --) {
			if (a[i] > '0') {
				a[i] -= 1;
				break;
			}
			else a[i] = '9';
		}
	}
	else a[len - 1] -= 1;
}


long long calc(string &N) {
	init();
	int len = N.size();
	for (int num = 1 ; num <= 9 ; num ++) {
		if (num == d) continue;
		int status;
		if (num < N[0] - '0') status = 0;
		else if (num == N[0] - '0') status = 1;
		else if (num > N[0] - '0') status = 2;
		dp[1][num % m][status] ++; 
	}
	for (int i = 1 ; i < len ; i++) {
		for (int r = 0 ; r < m ; r ++) {
			for (int status = 0 ; status <= 2 ; status++) {
				if (dp[i][r][status] == 0) continue;
				long long val = dp[i][r][status];
				if (i % 2 == 1) { 
						int newstatus = status;
						int newr = (r*10 + d)%m;
						if (newstatus == 1) {
							if (d < N[i] - '0') newstatus = 0;
							else if (d > N[i] - '0') newstatus = 2;
						}
						dp[i + 1][newr][newstatus] = (dp[i+1][newr][newstatus] + val)%mod;
				
				}
				else {
					for (int num = 0 ; num <= 9 ; num ++) {
						if (num == d) continue;
						int newstatus = status;
						int newr = (r * 10 + num)%m;
						if (newstatus == 1) {
							if (num < N[i] - '0') newstatus = 0;
							else if (num > N[i] - '0') newstatus = 2;
						}
						dp[i + 1][newr][newstatus] = (dp[i + 1][newr][newstatus] + val)%mod;
					}
				}
			}
		}
	}
	long long ans = 0;
	for (int i = 1 ; i <= len ; i++) {
		for (int status = 0 ; status <= (i < len ? 2 : 1) ; status++) {
			ans = (ans + dp[i][0][status])%mod ;
		}
	}
	return ans;
}


int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cin >> m >> d;
	cin >> a >> b;
	solve();
	if (a[0] == '0') a.erase(0,1);
	cout << (calc(b) - calc(a) + mod)%mod;

	return 0;
}