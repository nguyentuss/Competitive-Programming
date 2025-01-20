#include <bits/stdc++.h>

using namespace std;

string L , R;
long long dp[17][18][3];

void change(){
	int len = L.size();
	if (L[len - 1] == '0') {
		for (int i = len - 1 ; i >= 0 ; i --) {
			if (L[i] > '0') {
				L[i] -= 1;
				break;
			}
			else L[i] = '9';
		}
	}
	else L[len - 1] -= 1;
}

long long solve(string &N) {
	int len = N.size();
	long long res = 0;
	for (int num = 1 ; num <= 9 ; num++) {
		for (int i = 0 ; i <= 15 ; i++) {
			for (int j = 0 ; j <= 15 ; j++) {
				for (int status = 0 ; status <= 2 ; status++) 
					dp[i][j][status] = 0;
			}
		}
		for (int d = 1 ; d <= 9 ; d++) {
			int status;
			if (d < N[0] - '0') status = 0;
			else if (d == N[0] - '0') status = 1;
			else status = 2 ;
			dp[1][num == d][status] ++;
		}
		for (int i = 1 ; i < len ; i++) {
			for (int cnt = 0 ; cnt <= i ; cnt ++) {
				for (int status = 0 ; status <= 2 ; status ++) {
					if (!dp[i][cnt][status]) continue;
					long long value = dp[i][cnt][status];
					for (int d = 0 ; d <= 9 ; d ++) {
						int newstatus = status;
						int newcnt = cnt + (num == d ? 1 : 0);
						if (newstatus == 1) {
							if (d < N[i] - '0') newstatus = 0;
							else if (d > N[i] - '0') newstatus = 2;
						}
						dp[i + 1][newcnt][newstatus] += value;
					}
				}
			}
		}
		for (int i = 1 ; i <= len ; i++) {
			for (int cnt = 1 ; cnt <= i ; cnt ++) {
				for (int status = 0 ; status <= (i == len ? 1 : 2) ; status++) 
					res += cnt*num*dp[i][cnt][status]; 
			}
		}
	}
	return res;
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.inp","r",stdin);
	//freopen("test.out","w",stdout);
	int t; cin >> t;
	while (t--){
		cin >> L >> R;
		change();
		if (L[0] == '0') L.erase(0,1);
		cout << solve(R) - solve(L) << '\n';
	}
	return 0;
}