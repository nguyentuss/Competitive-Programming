//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define le(x) (x << 1ll)
#define ri(x) ((x << 1ll) + 1)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
const int inf = 1e9;

void solve() {
    int n , m; cin >> n >> m;
    vector<vector<char>> a(n , vector<char>(m)); 
    tuple<int,int> Romeo, Juliet;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'R') {
                Romeo = {i , j};
            }
            if (a[i][j] == 'J') {
                Juliet = {i , j};
            }
        }
    }
    bool ok = false;
    
    auto check = [&](int x , int y) -> bool {
        return (0 <= x && x < n && 0 <= y && y < m);
    };
    
    vector<vector<bool>> vis(n , vector<bool>(m));

    function <void(int , int)> BFS = [&](int x , int y) {
        if (vis[x][y] || a[x][y] == 'x') return;
        vis[x][y] = true;
        if (x == get<0>(Juliet) && y == get<1>(Juliet)) {
            ok = true;
            return;
        }   
        if (check(x + 1 , y)) BFS(x + 1 , y); 
        if (check(x , y + 1)) BFS(x , y + 1);
        if (check(x - 1 , y)) BFS(x - 1 , y);
        if (check(x , y - 1)) BFS(x , y - 1);
    };
    BFS(get<0>(Romeo),get<1>(Romeo));
    cout << (ok ? "YES" : "NO");
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test; 
    test = 1;
    // cin >> test;
    while (test--) {
        solve();
    }
 
}
