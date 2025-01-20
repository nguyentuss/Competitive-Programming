//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int , pii> piii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
const int inf = 1e9;

void solve() {
    int type; cin >> type; 
    if (type == 1) {
        int n, m; cin >> n >> m;
        vector<vi> a(n + 1 , vi(n + 1));
        for (int i = 1 ; i <= n ; i++) {
            for (int j = 1 ; j <= n ; j++) {
                cin >> a[i][j]; 
                a[i][j] = (a[i][j] < m ? 1 : 0);
            }
        }
        deque<tuple<int , int , int>> q;
        q.push_back({a[1][1] , 1 , 1});
        vector<vector<int>> f(n + 1 , vector<int>(n + 1 , inf)); 
        int dx[] = {1 , -1 , 0 , 0}; 
        int dy[] = {0 , 0 , 1 , -1};
        f[1][1] = a[1][1];
        while (!q.empty()) {
            auto [du , x , y] = q.front();
            q.pop_front();
            if (f[x][y] != du) continue;;
            for (int i = 0 ; i < 4 ; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i]; 
                if (1 <= nx && nx <= n && 1 <= ny && ny <= n) {
                    int w = a[nx][ny];
                    if (f[nx][ny] > f[x][y] + w) {
                        f[nx][ny] = f[x][y] + w;
                        if (w == 1) {
                            q.push_back({f[nx][ny] , nx , ny});
                        }
                        else {
                            q.push_front({f[nx][ny] , nx , ny});
                        }
                    }
                }
            }
        }
        cout << f[n][n];
    }
    else {
        int n; cin >> n;
        vector<vi> a(n + 1 , vi(n + 1));
        for (int i = 1 ; i <= n ; i++) {
            for (int j = 1 ; j <= n ; j++) {
                cin >> a[i][j];
            }
        }
        int dx[] = {1 , -1 , 0 , 0};
        int dy[] = {0 , 0 , 1 , -1};
        int l = 1 , r = inf; 
        auto check = [&](int X) -> bool {
            vector<vector<bool>> vis(n + 1, vector<bool> (n + 1));
            if (a[1][1] < X) return false;
            queue<tuple<int , int>> q;
            vis[1][1] = true;
            q.push({1 , 1});
            
            while (!q.empty()) {
                auto [x , y] = q.front(); 
                q.pop();
                //if (vis[x][y]) continue;
                for (int i = 0 ; i < 4 ; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i]; 
                    if (1 <= nx && nx <= n && 1 <= ny && ny <= n && !vis[nx][ny] && a[nx][ny] >= X) {
                        vis[nx][ny] = true; 
                        q.push({nx , ny});
                    }
                }
            }
            // for (int i = 1 ; i <= n ; i++) {
            //     for (int j = 1 ; j <= n ; j++) {
            //         cout << vis[i][j] ;
            //     }
            //     cout << '\n';
            // }
            return vis[n][n];
        };
        //cout << check(3);
        int res = 1;
        while (l <= r) {
            int mid = (l + r) >> 1; 
            if (check(mid)) {
                res = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        cout << res;
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test; 
    test = 1;
    //cin >> test;
    while (test--) {
        solve();
    }

}