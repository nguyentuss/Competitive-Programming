#include <bits/stdc++.h>

using namespace std;

#define MAX_L 20

string N;
long long dp[MAX_L][4][7][3];


void init(){
	for (int i = 0 ; i < MAX_L ; i++) 
		for (int cnt4 = 0 ; cnt4 < 4; cnt4++)
			for (int cnt7 = 0 ; cnt7 < 7 ; cnt7++) 
				for (int status = 0 ; status < 3 ; status ++) 
					dp[i][cnt4][cnt7][status] = 0;
}

void solve(const string &N){
	int len = (int) N.size();
	for (int d = 1 ; d <= 9 ; d++) {
		int status;	
		if (d < N[0] - '0') status = 0;
		else if (d == N[0] - '0') status = 1;
		else if (d > N[0] - '0') status = 2;
		dp[1][d == 4 ? 1 : 0][d == 7 ? 1 : 0][status] ++;

	}
	for (int i = 1 ; i < len ; i++) {
		for (int cnt4 = 0 ; cnt4 < 4 ; cnt4 ++) {
			for (int cnt7 = 0 ; cnt7 < 7 ; cnt7 ++) {
				for (int status = 0 ; status < 3 ; status++) {
					if (dp[i][cnt4][cnt7][status] == 0) 	
						continue;
					long long value = dp[i][cnt4][cnt7][status];
					for (int d = 0 ; d <= 9 ; d++) {
						int newcnt4 = (cnt4 + (d == 4 ? 1 : 0)) % 4;
						int newcnt7 = (cnt7 + (d == 7 ? 1 : 0)) % 7;
						int newStatus = status;
						if (status == 1) {
              				if (d < N[i] - '0') {
                			newStatus = 0;
              				}
              				else if (d > N[i] - '0') {
               	 				newStatus = 2;
              				}
              			}
              			dp[i + 1][newcnt4][newcnt7][newStatus] += value;
              		//	cout << i + 1 << " " << newcnt4 << " " << newcnt7 << " " << newStatus << " ";
					//	cout << dp[i+1][newcnt4][newcnt7][newStatus] << endl;
					}
				}
			}
		}
	}
	long long ans = 0;
	cout << dp[2][0][0][0] << endl;
  	for (int i = 1; i <= len; i++) {
    	for (int status = 0; status <= (i < len ? 2 : 1); status++) {
     	 ans += dp[i][0][0][status];
    	}
  	}
  	cout << ans << endl;
}



int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	freopen("4and7.inp","r",stdin);
	freopen("4and7.out","w",stdout);

	int t; cin >> t;

	for (int testcase = 0 ; testcase < t ; testcase++) {
		cin >> N;
		init();
		solve(N);
	}

	return 0;
}