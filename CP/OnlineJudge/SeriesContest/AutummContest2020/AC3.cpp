#include <bits/stdc++.h>

using namespace std;

#define MOD (int) (1e9 + 7)

int f[52][52][52][102];
int n , g , k;
int a[52];

void init() {
	for (int i = 0 ; i <= 50 ; i++) {
		for (int group = 0 ; group <= 50 ; group++) {
			for (int opengroup = 0 ; opengroup <= 50 ; opengroup ++) {
				for (int total = 0 ; total <= 100 ; total++) {
					f[i][group][opengroup][total] = 0;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		init();
		cin >> n >> g >> k;
		for (int i = 1 ; i <= n ; i++) {
			cin >> a[i];
		}
		sort(a + 1 , a + 1 + n);
		f[0][0][0][0] = 1;
		for (int i = 0 ; i < n ; i++) {
			for (int group = 0 ; group <= g ; group++) {
				for (int openGroup = 0 ; openGroup <= g ; openGroup ++) {
					for (int totalCost = 0 ; totalCost <= k ; totalCost ++) {
						if (f[i][group][openGroup][totalCost] == 0) continue;
						if (totalCost + openGroup * (a[i + 1] - a[i]) <= k) {
							int nextval = totalCost + openGroup * (a[i + 1] - a[i]);
							(f[i + 1][group + 1][openGroup + 1][nextval] 
							+= f[i][group][openGroup][totalCost]) %= MOD; 
							(f[i + 1][group + 1][openGroup][nextval] += f[i][group][openGroup][totalCost])%=MOD;
							if (openGroup > 0) {
								(f[i + 1][group][openGroup - 1][nextval] 
								+= (1LL*openGroup * f[i][group][openGroup][totalCost])%MOD) %= MOD;
							}
							(f[i + 1][group][openGroup][nextval] 
								+= (1LL*openGroup * f[i][group][openGroup][totalCost])%MOD) %= MOD;
							
						}
					}
				}
			}
		}
		int ans = 0;
		for (int total = 0 ; total <= k ; total++) {
			(ans += f[n][g][0][total])%=MOD;
		}
		cout << ans << '\n';
	}
	return 0;
}