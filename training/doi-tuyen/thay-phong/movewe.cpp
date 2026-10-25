#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define lim (int) (1e9 + 7)

ll dp[1007][1007];
ll a[1007][1007];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	ll n,m;cin>>n>>m;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			cin>>a[i][j];
		}
	}
	for (int i=0;i<=n;i++) 
		dp[i][0]=-lim;
	for (int i=0;i<=m;i++) 
		dp[0][i]=-lim;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			if (i==1 && j==1) dp[i][j]=a[i][j];
			else dp[i][j]=a[i][j]+max(dp[i][j-1],dp[i-1][j]); 
		}
	}
	cout << dp[n][m];
	return 0;
}