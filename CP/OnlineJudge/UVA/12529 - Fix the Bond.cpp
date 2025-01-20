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
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
const int inf = 1e9;
const int N = 700;

int n;
char a[N][N]; 
int vis[N][N];
int d[N][N][4];

int dx[] = {0 , 0 , 1 , -1};
int dy[] = {1 , -1 , 0 , 0};

bool inside(int x , int y) {
    return (x >= 0 && y >= 0 && x < 2*n && y < 2*n + 1);
}

void BFS(int i , int j) {
    queue<pii> q; 
    vis[i][j] = true; 
    q.push({i , j});
    while (!q.empty()) {
        auto [x , y] = q.front(); 
        cerr << x << " " << y << '\n';
        q.pop();
        for (int i = 0 ; i < 4 ; i++) {
            int tx = x + dx[i]; 
            int ty = y + dy[i]; 
            if (inside(tx , ty) && !vis[tx][ty] && d[x][y][i]) {
                cerr << tx << " " << ty << " " << i << '\n';
                vis[tx][ty] = 1; 
                q.push({tx , ty});
            }
        }
    }
    for (int i = 0 ; i < 2 *n ; i++) {
        for (int j = 0 ; j < 2 *n + 1 ; j++) {
            cerr << vis[i][j] << " ";
        }
        cerr << '\n';
    }
}

void solve() {
    cin >> n;
    for (int i = 0 ; i < 2*n - 1 ; i++) {
        int x = i , y = x & 1;
        for (int j = 0 ; j < n ; j++ , y += 2) {
            cin >> a[i][j];
            if (a[i][j] == 'H') {
                d[x][y][0] = d[x][y + 1][0] = 1; 
                d[x + 1][y][1] = d[x + 1][y + 1][1] = 1;
            }
            else {
                d[x][y][2] = d[x + 1][y][2] = 1; 
                d[x][y + 1][3] = d[x + 1][y + 1][3] = 1;
            }
            if (i == 1)
            cout << i << " " << d[2][3][2] << '\n';
        }
    }
    int ans = 0;
    BFS(0 , 0);
    // for (int i = 0 ; i < 2 * n ; i++) {
    //     for (int j = 0 ; j < 2 * n + 1 ; j++) {
    //         if (!vis[i][j]) {
    //             cerr << i << " " << j << '\n';
    //             BFS(i , j);
    //             ans++;
    //         }
    //     }
    // }
    cout << ans - 1 << '\n';
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