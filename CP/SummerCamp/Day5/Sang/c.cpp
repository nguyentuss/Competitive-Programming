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
const int inf = 1e18 + 7;
const int MAX_N = 3e3 + 7 ;
const int MOD = 1e9 + 7;

int a[MAX_N] , f[MAX_N][MAX_N] , g[MAX_N][MAX_N]; 

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for (int i = 1 ; i <= n ;i ++) {
        cin >> a[i];
        for (int j = n ; j >= 0 ; j--) {
            f[i][j] = g[i][j] = -inf;
        }
    }
    for (int i = 1 ; i < n ;i ++) {
        g[1][i] = a[1];
        f[1][i] = a[1];
    }
    for (int i = 2 ; i <= n ; i ++) {
        for (int j = i - 1; j >= 1 ; j--) {
            int x = i - j;
            f[i][j] = max(f[i][j] , a[i] + g[x][j]);
        }
        for (int j = i ; j >= 0 ; j --) {
            g[i][j] = max(g[i][j + 1] , f[i][j]);
        }
    }
    for (int i = 1 ; i <= n ;i ++) {
        for (int j = 1 ; j <= i ; j++) {
            //cout << g[i][j] << " ";
            //cerr << f[i][j] << " ";
        }
        //cout << '\n';
   //     cerr << '\n';
    }
    int ans = -inf;
    for (int i = 1 ; i <= n ;i ++) {
        ans = max(ans , f[n][i]);
    }
    cout << ans;
    return 0;
}
 