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
const int inf = 2000;
const int MAX_N = 1e3 + 7;
const int MOD = 1e9 + 7;

char a[MAX_N][MAX_N];
char b[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];
int f[MAX_N][MAX_N];
ii deff[MAX_N][MAX_N];
int n , m;

void calc(int type) {
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            int posx = deff[i][j].fi , posy = deff[i][j].se;
            int x = inf;
            if (a[i][j] == 'B') {
                if (type == 1)
                    x = posx + posy;
                if (type == 2) 
                    x = posx - posy;
                if (type == 3) 
                    x = posy - posx;
                if (type == 4) 
                    x = -posx - posy;
            }
            f[i][j] = min({f[i][j - 1] , f[i - 1][j] , x});
            if (type == 1) dp[posx][posy] = max(dp[posx][posy] , (posx + posy) - f[i][j]);
            if (type == 2) dp[posx][posy] = max(dp[posx][posy] , (posx - posy) - f[i][j]);
            if (type == 3) dp[posx][posy] = max(dp[posx][posy] , (posy - posx) - f[i][j]);
            if (type == 4) dp[posx][posy] = max(dp[posx][posy] , (-posx - posy) - f[i][j]);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        cin >> n >> m;
        ii pos;
        int ans = inf;
        for (int i = 1 ; i <= n ; i++) {
            for (int j = 1 ; j <= m ; j ++) {
                f[i][j] = dp[i][j] = 0;
            }
        }
        for (int i = 1 ; i <= n ;i++) {
            f[i][0] = f[i][m + 1] = inf;
            for (int j = 1 ; j <= m ; j++) {
                cin >> b[i][j];
                deff[i][j] = ii(i , j);
                a[i][j] = b[i][j];
                f[0][j] = f[n + 1][j] = inf;
            }
        }
        calc(1);
        
        int cnt = 0;
        for (int i = 1 ; i <= n ; i++) {
            cnt = 0;
            for (int j = m ; j >= 1 ; j--) {
                a[i][++cnt] = b[i][j];
                deff[i][cnt] = ii(i , j);
            }
        }
        calc(2);
        // for (int i = 1 ; i <= n ; i++) {
        //     for (int j = 1 ; j <= m ; j++) {
        //         cerr << dp[i][j] << " ";
        //     }
        //     cerr << '\n';
        // }
        cnt = 1;
        for (int i = n ; i >= 1 ; i--) {
            for (int j = 1 ; j <= m ; j++) {
                a[cnt][j] = b[i][j];
                deff[cnt][j] = ii(i , j);
            }
            ++cnt;
        }
        calc(3);
        cnt = 1;
        for (int i = n ; i >= 1 ; i--) {
            int cnt1 = 0;
            for (int j = m ; j >= 1 ; j--) {
                a[cnt][++cnt1] = b[i][j];
                deff[cnt][cnt1] = ii(i , j);
            }
            ++cnt;
        }
        calc(4);
        for (int i = 1 ; i <= n ; i++) {
            for (int j = 1; j <= m ; j++) {
                if (ans > dp[i][j]) {
                    ans = dp[i][j];
                    pos = ii(i , j);
                }
            }
        }
        cout << pos.fi << " " << pos.se << '\n';
    }
    return 0;
}
/* |a - xi| + |b - yi|
    if (a >= xi && b>= yi)
    => a - xi + b - yi => (a + b) - (xi + yi)
    if (a >= xi && b < yi) 
    => a - xi + yi - b => (a - b) - (xi - yi)
    if (a < xi && b >= yi) 
    => xi - a + b - yi => (b - a) - (yi - xi)
    if (a < xi && b < yi) 
    => xi - a + yi - b => (-a - b) - (-xi - yi)

*/