#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int MAX_N = 3007;
const int MOD = 1e9 + 7;
 
int r, c, n, dp[MAX_N][MAX_N], fact[MAX_N * MAX_N], C[MAX_N][MAX_N];
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    fact[0] = 1;
    for(int i = 1; i < MAX_N * MAX_N; i++)
        fact[i] = (ll) fact[i - 1] * i % MOD;
    for(int i = 0; i < MAX_N; i++){
        C[i][0] = 1;
        for(int j = 1; j <= i; j++)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
    }
 
    cin >> r >> c >> n;
    int minX = MAX_N , maxX = 0, minY = MAX_N, maxY = 0;
    for(int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        minX = min(minX, x);
        maxX = max(maxX, x);
        minY = min(minY, y);
        maxY = max(maxY, y);
    }
    int r0 = maxX - minX + 1;
    int c0 = maxY - minY + 1;
    dp[r0][c0] = fact[r0 * c0 - n];
    for(int i = r0; i <= r; i++)
        for(int j = c0; j <= c; j++){
            if (i < r)
                dp[i + 1][j] = (dp[i + 1][j] + (ll) dp[i][j] * fact[j]) % MOD;
            if (j < c)
                dp[i][j + 1] = (dp[i][j + 1] + (ll) dp[i][j] * fact[i]) % MOD;
        }
    /*for (int i = r0 ; i <= r ; i++) {
        for (int j = c0 ; j <= c ; j++) {
            cout << dp[i][j] << " " ;
        }
        cout << '\n';
    }*/
   // cout << (ll) dp[r][c] * C[r - r0][minX - 1] % MOD * C[c - c0][minY - 1] % MOD;
    cout << dp[r][c] * C[c - c0][minY - 1];
    return 0;
}