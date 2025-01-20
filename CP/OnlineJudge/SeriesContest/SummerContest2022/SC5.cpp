#include <bits/stdc++.h>
 
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
 
using namespace std;

#define ii pair<int , int>
#define f first
#define s second
#define int long long
const int inf = 1e9 + 7;
const int MAX_N = 2e5 + 7;
const int MOD = 1e9 + 7;

int f[2][1 << 10][21][21];

// gọi f[i][j][mask][cow][pair] là số cách để xếp cow con bò và có pair cặp và cái mask theo kĩ thuật broken profile

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n , m , c , k; cin >> n >> m >> c >> k;
        if (n > m) swap(n , m);
        memset(f , 0 , sizeof(f));
        f[0][0][0][0] = 1;
        for (int j = 0 ; j < m ; j++) {
            for (int i = 0 ; i < n ; i++) {
                for (int mask = 0 ; mask < (1 << n) ; mask++) {
                    for (int sl = 0 ; sl <= c ; sl ++) {
                        for (int pr = 0 ; pr <= k ; pr++) {
                            // khi đặt (i , j) là cỏ
                            if (!(mask & (1 << i))) {
                                // đặt (i , j) là cỏ khi thằng a[i][j - 1] là bit 0
                                (f[1][mask][sl][pr] += f[0][mask][sl][pr])%=MOD;
                                // đặt (i , j) là cỏ khi thằng a[i][j - 1] là bit 1
                                (f[1][mask][sl][pr] += f[0][mask ^ (1 << i)][sl][pr])%=MOD; 
                            }
                            else {
                                if (!(mask & (1 << i - 1))) {
                                    if (sl) {   
                                        // đặt (i , j) là bò khi thằng a[i][j - 1] là bit 0 và bắt buộc a[i - 1][j] phải là bit = 0
                                        (f[1][mask][sl][pr] += f[0][mask ^ (1 << i)][sl - 1][pr])%=MOD;
                                        // đặt (i , j) là bò khi a[i][j - 1] là bit 1 và a[i - 1][j] là bit 0
                                        if (pr)
                                        (f[1][mask][sl][pr] += f[0][mask][sl - 1][pr - 1])%=MOD;
                                    }
                                }
                                else {
                                    if (sl && pr) {
                                        // đặt (i , j) là bò khi a[i][j - 1] là bit 0 và a[i - 1][j] là bit 1
                                        (f[1][mask][sl][pr] += f[0][mask ^ (1 << i)][sl - 1][pr - 1])%=MOD;
                                        if (pr >= 2) {
                                            // đặt (i , j) là bò khi a[i][j - 1] là bit 1 và a[i - 1][j] là bit 1
                                            (f[1][mask][sl][pr] += f[0][mask][sl - 1][pr - 2])%=MOD;    
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                for (int mask = 0 ; mask < (1 << n) ; mask++) {
                    for (int sl = 0 ; sl <= c ; sl ++) {
                            for (int pr = 0 ; pr <= k ; pr++) {
                                f[0][mask][sl][pr] = f[1][mask][sl][pr];
                                f[1][mask][sl][pr] = 0;
                            }
                    }
                }
            }
        }
        int ans = 0;
        for (int mask = 0 ; mask < (1 << n) ; mask++) {
            for (int pr = 0 ; pr <= k ; pr++) {
                (ans += f[0][mask][c][pr])%=MOD;    
            }
        }
        cout << ans << '\n';
    }
    return 0;
}