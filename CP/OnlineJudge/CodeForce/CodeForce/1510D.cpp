#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)
#define inf (int) (-1e9)

int n , d;
double dp[MAX_N][11];
int trace[MAX_N][11];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.inp","r",stdin);
	//freopen("test.out","w",stdout);
	cin >> n >> d;
	vector<int> a(n + 1);
	for (int i = 1 ; i <= n ; i++) 
		cin >> a[i];
	for (int i = 0 ; i <= n ;i++) {
		for (int j = 0 ; j < 10 ; j++) {
			dp[i][j] = -1e30;
			trace[i][j] = -1;
		}
	}
	dp[0][1] = 0;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 0 ; j < 10 ; j++) 
			dp[i][j] = dp[i - 1][j];
		for (int j = 0 ; j < 10 ; j++) {
			int tmp = (j*a[i])%10;
			if (dp[i][tmp] < (dp[i - 1][j] + log(a[i]))) {
				dp[i][tmp] = dp[i - 1][j] + log(a[i]);
				trace[i][tmp] = j;
			}
		}
	}
	int len = n;
	int tmp = d;
	vector<int> ans;
	while (len) {
		if (trace[len][tmp] != -1) {
			tmp = trace[len][tmp];
			ans.push_back(a[len]);
		}
		len--;
	}
	if (!ans.size()) cout << -1;
	else {
		cout << ans.size() << '\n';
		for (auto x : ans) cout << x << " ";
	}
		return 0;
}