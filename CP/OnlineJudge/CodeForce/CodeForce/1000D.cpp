#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e3 + 7)
#define MOD (int) (998244353)
#define int long long

int C[MAX_N][MAX_N];
int f[MAX_N][MAX_N];
int sum[MAX_N];
int a[MAX_N];

void calc() {
    for (int i = 0 ; i < MAX_N ; i++) {
        C[i][i] = 1;
        C[i][0] = 1;
    }
    for (int i = 1 ; i < MAX_N ; i++) {
        for (int j = 1 ; j < i ; j++) {
            (C[i][j] = C[i - 1][j] + C[i - 1][j - 1]) %= MOD;
        }
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
    }
    calc();
    // f[i][j] = sigma(f[i'][i - 1])*CNK(j - i , a[i]) i' < i
    for (int i = 0 ; i <= n ; i++) sum[i] = 1;
    for (int i = 1 ; i <= n ; i++) {
        if (a[i] <= 0) continue;
        for (int j = i + a[i] ; j <= n ; j++) {
            (f[i][j] += (sum[i - 1]*C[j - i][a[i]]))%=MOD;
        }   
        for (int j = i + a[i] ; j <= n ; j++) {
            (sum[j] += f[i][j])%=MOD;
        }
    }
    int ans = 0;
    for (int i = 1 ; i <= n ;i ++) {
        cerr << i << " " << f[i][n]  << " " << sum[i] << '\n';
        (ans += f[i][n])%=MOD; 
    }
    cout << ans;
    return 0;
}