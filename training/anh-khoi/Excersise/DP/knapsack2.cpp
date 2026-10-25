#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

#define MAX_W (int) (1e9 + 7)
#define MAX_V (int) (1e5 + 7)
#define INF (int) (1e9 + 7)

long long N , M;
vector <long long> W(101);
vector <long long> v(101);
long long dp[101][MAX_V];
long long maxvalue = 0;

void init() {
	for (int i = 0 ; i < 101 ; i++) 
		for (int j = 0 ; j < MAX_V ; j ++) 
			dp[i][j] = INF;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	//freopen("knapsack2.inp","r",stdin);
	//freopen("knapsack2.out","w",stdout);
	cin >> N >> M;
	for (int i = 1 ; i <= N ; i++){ 
		cin >> W[i] >> v[i];
		maxvalue += v[i];
	}
	init();
	for (int i = 0 ; i <= N ; i++) dp[i][0] = 0;
	for (int i = 0 ; i < N ; i++) 
		for (int j = 0 ; j <= maxvalue ; j++) {
			if (dp[i][j] == INF) continue;
			dp[i + 1][j] = min(dp[i + 1][j] , dp[i][j]);
			if (dp[i][j] + W[i + 1] <= M) 
				dp[i + 1][j + v[i + 1]] = min(dp[i + 1][j + v[i + 1]] , dp[i][j] + W[i + 1]);
		}
	int ans = -INF;
	for (int j = 0 ; j <= maxvalue; j++) {
		if (dp[N][j] <= M && j >= ans) 
			ans = max(ans , j);
	}
	cout << ans;
	return 0;
}