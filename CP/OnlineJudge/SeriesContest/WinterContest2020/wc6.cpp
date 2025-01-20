#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX_N (int) 12
#define MAX_K (int) 85
#define M (int) (1e9 + 7)

string N;
int k;
ll f[MAX_N][MAX_K][MAX_K][MAX_K][3];

void init() {
	for (int i = 0 ; i <= 11 ; i++) {
		for (int multi = 0 ; multi < MAX_K ; multi++) {
			for (int sum = 0 ; sum < MAX_K ; sum ++) {
				for (int r = 0 ; r < MAX_K ; r++) {
					for (int status = 0 ; status <= 2 ; status++) {
						f[i][multi][sum][r][status] = 0;
					}
				}
			}
		}
	}
}

ll dynamicProgramming() {
	if (k > MAX_K) return 0LL;
	init();
	int len = N.size();
	for (int num = 1 ; num <= 9 ; num++) {
		int status;
		if (num < N[0] - '0') status = 0;
		else if (num == N[0] - '0') status = 1;
		else status = 2;
		f[1][num % k][num % k][num % k][status] ++;
	}
	for (int i = 1 ; i < len ; i++) {
		for (int multi = 0 ; multi < k ; multi++) {
			for (int sum = 0 ; sum < k ; sum++) {
				for (int r = 0 ; r < k ; r++) {
					for (int status = 0 ; status <= 2 ; status++) {
						if (f[i][multi][sum][r][status] == 0) continue;
						ll val = f[i][multi][sum][r][status];
						for (int num = 0 ; num <= 9 ; num++) {
							int newstatus = status;
							int newmulti = (multi*num)%k;
							int newsum = (sum + num)%k;
							int newr = (r*10 + num)%k;
							if (newstatus == 1) {
								if (num < N[i] - '0') newstatus = 0;
								else if (num > N[i] - '0') newstatus = 2;
							}
							f[i + 1][newmulti][newsum][newr][newstatus] = (f[i + 1][newmulti][newsum][newr][newstatus] + val)%M;
						}
					}
				}
			}
		}
	}
	ll res = 0LL;
	for (int i = 1 ; i <= len ; i++) {
		for (int status = 0 ; status <= (i < len ? 2 : 1) ; status++) {
			res = (res + f[i][0][0][0][status])%M;
		}
	}
	return res%M;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		cin >> N >> k;
		cout << dynamicProgramming() << '\n';
	}
	return 0;
}