#include <bits/stdc++.h>

#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long
const int inf = 1e9 + 7;
const int MAX_N = 1e6 + 7;
const int MOD = 1e9 + 7;


int POW(int a , int n) {
    if (n == 1) return a;
    int child = POW(a , n / 2)%MOD; 
    if (n % 2) {
        return ((child*child)%MOD*a)%MOD;
    }
    else return (child*child)%MOD;
}

int frac[MAX_N];
int inv[MAX_N];
int f[MAX_N];
int save[MAX_N];

int CnK(int n , int k) {
    return (frac[n]%MOD*save[k]%MOD*save[n - k]%MOD)%MOD;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    f[0] = 1;
    f[1] = 1;
    for (int i = 1 ; i <= n ; i ++) {
        f[i] = ((i - 1)*f[i - 2])%MOD;
    }
    frac[0] = 1;
    for (int i = 1 ; i <= n ; i++) {
        frac[i] = (frac[i - 1]*i)%MOD;
    }
    for (int i = 0 ; i <= n ; i++) {
        save[i] = POW(frac[i] , MOD - 2)%MOD;
    }
    int ans = 0;
    for (int i = 0 ; i <= n ; i++) {
        ans = (ans + (CnK(n , i)%MOD*f[i]%MOD*f[i]%MOD)%MOD)%MOD;
    }
    cout << ans;
    return 0;
}