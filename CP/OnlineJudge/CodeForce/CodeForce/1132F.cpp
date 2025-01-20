#include <bits/stdc++.h>

using namespace std;

#define inf (int) (1e9 + 7)

int f[507][507];
int n;
string s;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n;
	cin >> s;
	vector<vector<int>>dp(n+2,vector<int>(n+2,0));
    for(int i=n;i>=1;i--){
        for(int j=i;j<=n;j++){
            if(i==j){
                dp[i][j]=1;
                continue;
            }
            dp[i][j]=1+dp[i+1][j];
            for(int k=i+1;k<=n;k++){
                if(s[i-1]==s[k-1])
                dp[i][j]=min(dp[i][j],dp[i+1][k]+dp[k+1][j]);
            }
        }
    }	
    cout<<dp[1][n];
	return 0;
}