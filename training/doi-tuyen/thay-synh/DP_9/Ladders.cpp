//
// Created by tuloc on 3/26/2024.
//
#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 2007;
const int MOD = 301907;

int f[N][N];
//

void solve() {
    int n;

    cin >> n;

    vector<int> dp(n + 1);

    dp[0] = 1;

    for (int i = 1 ; i <= n ; i++) {
        for (int j = n ; j >= i ; j--) {
            dp[j] += dp[j - i];
        }
    }

    cout << dp[n];
}


signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}