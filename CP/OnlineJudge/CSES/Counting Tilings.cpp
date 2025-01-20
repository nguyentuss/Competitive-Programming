#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
#pragma GCC optimize("Ofast")
#define MOD (int) (1e9 + 7)
 
signed main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    cout.tie(NULL);
    int n , m; cin >> n >> m;
    vector<vector<int>> f(2 , vector<int>((1 << n) + 1, 0));
    f[0][0] = 1;    
    for (int j = 0 ; j < m ; j++) {
        for (int i = 0 ; i < n ; i++) {
            for (int mask = 0 ; mask < (1 << n) ; mask++) {
                // lap tile 2x1 thang dung va khong lap
                (f[1][mask] = f[0][mask ^ (1 << i)])%=MOD;
                if (i && !(mask & (1 << i)) && !(mask & (1 << (i - 1)))) {
                    // lap title 1x2 hang ngang
                    (f[1][mask] += f[0][mask | (1 << (i - 1))])%=MOD;
                }
            }
            for (int mask = 0 ; mask < (1 << n) ; mask++) {
                f[0][mask] = f[1][mask];
                f[1][mask] = 0;
            }
        }
    }
    cout << f[0][0];
 
    return 0;
}