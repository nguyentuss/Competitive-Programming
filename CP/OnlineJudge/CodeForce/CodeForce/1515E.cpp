#include <bits/stdc++.h>

using namespace std;

#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define MAX_N (int) (4e2 + 7) 
#define int long long

int f[MAX_N][MAX_N];
int C[MAX_N][MAX_N];
int POW[MAX_N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.tie(0);
    int n , M; cin >> n >> M;
    for (int i = 0 ; i <= n ; i ++) {
        C[i][i] = 1;
        C[i][0] = 1;
    }
    POW[0] = 1;
    for (int i = 1 ; i <= n ; i++) {
        (POW[i] = POW[i - 1]*2)%=M;
        for (int j = 1 ; j <= i ; j++) {
            (C[i][j] = C[i - 1][j] + C[i - 1][j - 1])%=M;
        }
    }
    f[0][0] = 1;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            for (int k = 1 ; k <= min(n - i , n - j) ; k++) {
                //if (i + k + 1 <= n + 1 && j + k <= n)
                (f[i + k + 1][j + k] += f[i][j]*POW[k - 1]%M*C[j + k][k]%M)%=M;
            }
        }
    }
    int ans = 0;
    for (int i = 0 ; i <= n ; i++) {
        (ans += f[n + 1][i])%=M;
    }
    cout << ans;
    return 0;
}