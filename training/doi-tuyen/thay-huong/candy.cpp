#include <bits/stdc++.h>

using namespace std;

#define inf (int) (1e9 + 7)

int n , m;
int dp[1001][20001];
vector <int> v(1001);
int total = 0;

typedef pair<int , int> ii;



void init(){
	for (int i = 1 ; i <= m ; i++)
		for (int j = 1 ; j <= n ; j++) {
			dp[i][j] = 0;
			//pre[i][j] = v[i - 1];
		}
}
int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	freopen("candy.inp","r",stdin);
	freopen("candy.out","w",stdout);
	cin >> n ;
	for (int i = 1 ; i <= n ; i++) {
		cin >> v[i];
		total += v[i];
	}
	v[0] = 0;
	init();
	for (int choose = 1 ; choose <= n ; choose++)
		for (int weigth = 1 ; weigth <= total ; weigth++) { 
			if (v[choose] > weigth) {
				dp[choose][weigth] = dp[choose - 1][weigth];
			}
			else {
				dp[choose][weigth] = max(dp[choose - 1][weigth] , dp[choose - 1][weigth - v[choose]] + v[choose]);
			}
		}
	/*for (int i = 1 ; i <= n; i++){
		for (int j = 1 ; j <= m ; j++)
			cout << dp[i][j] << " ";
		cout << endl;
	}
	*/
	int ans = inf;
	for (int i = 0 ; i <= total ; i++) 
		ans = min(ans , abs(dp[n][i] - (total - dp[n][i])));
	cout << ans;
	return 0;
}