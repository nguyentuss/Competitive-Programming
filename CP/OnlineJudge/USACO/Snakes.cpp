#include <bits/stdc++.h>

using namespace std;

#define inf (int) (1e9 + 7)

int f[407][407];
int a[407];
int sum[407];

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    int n , k; cin >> n >> k;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= k ; j++) {
            f[i][j] = inf;
        }
    }  
    f[0][0] = 1;
    int tm = 0;
    for (int i = 1 ; i <= n ; i++) {
        tm = max(tm , a[i]);
        f[i][0] = tm*i - sum[i];
        for (int j = 1 ; j <= min(i - 1 , k) ; j++) {
            int len = 0 , maxi = 0;
            for (int h = i ; h >= 1 ; h--) {
                len++; maxi = max(maxi , a[h]);
                f[i][j] = min(f[i][j] , maxi*len - (sum[i] - sum[h - 1]) + f[h - 1][j - 1]);    
            }
        }
    }
    int ans = inf;
    // for (int i = 1 ; i <= n ; i++) {
    //     for (int j = 1 ; j <= k ; j++) {
    //         cerr << f[i][j] << " ";
    //     }
    //     cerr << '\n';
    // }
    for (int j = 1 ; j <= k ; j++) ans = min(ans , f[n][j]);
    cout << ans;

    return 0;
}   