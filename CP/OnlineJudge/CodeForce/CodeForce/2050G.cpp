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
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 1 ; i < n ; i++) {
        int u , v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>> f(n , vector<int>(3));
    
    // 0 : chua xoa tai u
    // 1 : da xoa tai u nhung van con di tiep len p
    // 2 : da xoa tai u nhung kh the di tiep len p

    function<void(int , int)> DFS = [&](int u , int father) {
        f[u][0] = 1;
        int degree = 0;
        vector<int> b;
        for (int v : adj[u]) {
            if (v == father) continue;;
            DFS(v , u);
            degree ++;
            b.push_back(f[v][1]);
        }
        f[u][1] = max(f[u][1] , degree);
        sort(all(b),greater<int>());
        if (sz(b) > 1) {
            f[u][2] = max(f[u][2], b[0] + b[1] + degree - 2);
        }
        for (int v : adj[u]) {
            if (v == father) continue;
            f[u][0] = max(f[u][0] , max(f[v][1] , f[v][2]) + 1);
            f[u][0] = max(f[u][0] , f[v][0]);
            f[u][1] = max(f[u][1] , f[v][1] + degree - 1);
        }
    };
    DFS(0,-1); 
    // for (int i = 0 ; i < n ; i++) {
        // cerr << f[i][0] << ' ' << f[i][1] << ' ' << f[i][2] << '\n';
    // }
    int ans = 0;
    for (int i = 0 ; i < n ; i++) {
        ans = max({ans , f[0][0] , f[0][1] , f[0][2]});
    }
    cout << ans << '\n';
    // cout << max({f[0][0] , f[0][1] , f[0][2]}) << '\n';
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test; 
    test = 1;
    cin >> test;
    while (test--) {
        solve();
    }
 
}
