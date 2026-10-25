#include<iostream>
using namespace std;
int n,m,w[1005],v[1005];long long dp[1005][100005];
long long solve(){
    for(int i=0;i<=n;i++)dp[i][0]=0;
    for(int j=0;j<=m;j++)dp[0][j]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(w[i]>j) dp[i][j]=dp[i-1][j];
            else dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
        }
    }
    //for(int i=m-1;i>=1;i-=1)if(dp[n][i]==dp[n][m])ans=i;
return dp[n][m];
}
int main(){
   // freopen("BALO2.inp","r",stdin);
    //xfreopen("BALO2.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>w[i]>>v[i];
    //cout<<ans()<<" "<<solve();
    solve();int kq=m;
    for(int i=m-1;i>=1;i-=1){
        if(dp[n][i]==dp[n][m])kq=i;
        else break;
    }
    cout<<kq<<" "<<solve();
return 0;
}	