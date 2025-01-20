#include <bits/stdc++.h>

using namespace std;

#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops") 

#define int long long
#define MAX_N (int) (1e6 + 7)

const int MOD = 1e9 + 7;

int n , k;
int frac[MAX_N] , inv[MAX_N];

int POW(int a , int n) {
    if (n == 0) return 1;
    int child = POW(a , n / 2)%MOD;
    if (n % 2) return (child*child%MOD*a%MOD)%MOD;
    else return (child*child)%MOD;
}

int cnk(int n , int k) {
    return (frac[n]*inv[k]%MOD*inv[n - k]%MOD)%MOD;
}

void init() {
    frac[0] = 1;
    inv[0] = 1;
    for (int i = 1 ; i < MAX_N ; i++) {
        frac[i] = (frac[i - 1]*i)%MOD;
        inv[i] = POW(frac[i] , MOD - 2)%MOD;
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cin >> n >> k;
    init();
    int ans = 0;
    for (int i = 0 ; i <= k ; i++) {
        int status = (i & 1 ? -1 : 1);
        int tmp = (status*cnk(k , i)%MOD*POW(k - i , n)%MOD + MOD)%MOD;
        (ans = ans + tmp)%MOD;
    }
    cout << ans%MOD;
    return 0;
}