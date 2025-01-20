#include <iostream>
#include <algorithm>
#include <cmath>
#include <algorithm>


using namespace std;

#define MAX_L (long long) 12

string a , b; 
long long k;
long long dp[12][92][92][3];

void init(){
	for (int i = 0 ; i < MAX_L ; i++) 
		for (int r = 0 ; r < 92  ; r++) 
			for (int multi = 0 ; multi < 92 ; multi ++)  
				for (int status = 0 ; status < 3 ; status ++) 
					dp[i][r][multi][status] = 0;
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
		int status;
		if (num < N[0] - '0') status = 0;
		else if (num == N[0] - '0') status = 1;
		else if (num > N[0] - '0') status = 2;
		dp[1][num % k][num % k][status] ++;
	}
	for (int i = 1 ; i < len ; i++) {
		for (int r = 0 ; r < k ; r ++) {
			for (int multi = 0 ; multi < k ; multi ++) {
				for (int status = 0 ; status < 3 ; status ++) {
					if (dp[i][r][multi][status] == 0) continue;
					long long value = dp[i][r][multi][status];
					for (int num = 0 ; num <= 9 ; num ++) {
						long long newstatus = status;
						long long newr = (r*10 + num)%k;
						long long newmulti = (multi + num)%k;
						if (newstatus == 1) {
							if (num < N[i] - '0') newstatus = 0;
							else if (num > N[i] - '0') newstatus = 2;
						}
						dp[i + 1][newr][newmulti][newstatus] += value;
					}
				}
			}
		}
	}
	long long ans = 0;
	for (int i = 1 ; i <= len ; i++) {
		for (int status = 0 ; status <= (i < len ? 2 : 1) ; status ++)
			ans += dp[i][0][0][status];
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);

	int t;
	cin >> t; 
	for (int test = 0 ; test < t ; test ++) {
		cin >> a >> b >> k;
		if (k > 90) {
			cout << "Case " << test + 1 << ": " << 0 << endl;
			continue;
		}
		solve();
		if (a[0] == '0') a.erase(0,1);
		cout << "Case " << test + 1 << ": " << calc(b) - calc(a) << endl;
	} 

	return 0;
}