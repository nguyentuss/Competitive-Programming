#include <bits/stdc++.h>
using namespace std;
 
#define mod (long long) (1e9 + 7) 

int dp[10007][10007];

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    freopen("order.inp","r",stdin);
    freopen("order.out","w",stdout);
    long long  N , K; cin >> N >> K;
     
    for(long long  i = 1; i <= N; i++)
        dp[i][0] = 1%mod;
 
    for(long long i = 1; i <= N; i++)
    {
        for(long long j = 1; j <= K; j++)
        {
            long long  val = dp[i-1][j]%mod;
            if(j >= i)
                val = (val%mod - dp[i-1][j-i]%mod)%mod;
            dp[i][j] = (dp[i][j-1]%mod + val%mod)%mod;
        }
    }
    long long ans = dp[N][K]%mod;
    if(K >= 1)
        ans = (ans%mod - dp[N][K-1]%mod)%mod;
    cout << ans%mod;
    return 0;
}