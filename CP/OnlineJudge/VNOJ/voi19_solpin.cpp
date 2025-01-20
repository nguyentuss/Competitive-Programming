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

int a[507][507] , f[507][507];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n , m; cin >> n >> m;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j ++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + a[i][j];
        }
    }   

    function<int(int , int , int , int)> calc = [&] (int x1 , int y1 , int x2 , int y2) {
        int last_x = x2 - x1 + 1, last_y = y2 - y1 + 1;
        return (f[x2][y2] - f[x2][y2 - last_y] - f[x2 - last_x][y2] + f[x2 - last_x][y2 - last_y]);
    }; 

    function<bool(int , int)> check = [&](int x , int y) {
        return (x >= 1 && x <= n && y >= 1 && y <= m);
    };
    int total_R = 0 , total_D = 0;
    int q; cin >> q;
    for (int i = 1 ; i <= q ; i ++) {
        //cerr << "DEBUG" << '\n';
        int p; cin >> p;
        if (!p) {
            int x , y; cin >> x >> y;
            total_R += x , total_D += y;
        }
        else {
            int x1 , x2 , y1 , y2; cin >> x1 >> y1 >> x2 >> y2;
            int last_x = x2 - x1 , last_y = y2 - y1;
            int now_x1 = 0 , now_y1 = 0 , now_x2 = 0 , now_y2 = 0;
            now_x1 = x1 + total_D%n , now_y1 = y1 + total_R%m;
            if (now_x1 > n) now_x1 -= n;
            if (now_y1 > m) now_y1 -= m;
            now_x2 = now_x1 + last_x , now_y2 = now_y1 + last_y;
            //cout << now_x1 << " " << now_y1 << " " << now_x2 << " " << now_y2 << '\n';
            int res = 0;
            if (check(now_x1 , now_y1) && check(now_x2 , now_y2)) {
                cout << calc(now_x1 , now_y1 , now_x2 , now_y2) << '\n';
            }
            else if (now_x2 > n && now_y2 > m) {
                cout << calc(now_x1 , now_y1 , n , m) + calc(now_x1 , 1 , n , now_y2 - m) + calc(1 , 1 , now_x2 - n , now_y2 - m) 
                + calc(1 , now_y1 , now_x2 - n , m) << '\n';
            }
            else if (now_x2 <= n && now_y2 > m) {
                //cout << calc(now_x1 , now_y1 , now_x2 , m) << '\n';
                cout << calc(now_x1 , now_y1 , now_x2 , m) + calc(now_x1 , 1 , now_x2 , now_y2 - m) << '\n';
            }
            else if (now_x2 > n && now_y2 <= m) {
                cout << calc(now_x1 , now_y1 , n , now_y2) + calc(1 , now_y1 , now_x2 - n , now_y2) << '\n';
            }
        }
    }
    return 0;
}
