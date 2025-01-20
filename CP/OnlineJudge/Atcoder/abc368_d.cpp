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

void solve() {
    int n , k; cin >> n >> k;
    vector<vector<int>> adj(n);
    vector<int> g(n);
    for (int i = 1;  i < n ; i++) {
        int u , v; cin >> u >> v;
        u--; v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    int x;
    for (int i = 0 ; i < k ; i++) {
        cin >> x;
        x--;
        g[x] = true;
    }
    auto DFS = [&](int u , int father , auto && DFS) -> int {
        int st = g[u];
        int res = 0;
        bool stat = false;
        for (int v : adj[u]) {
            if (v != father) {
                int t = DFS(v , u , DFS); 
                if (t) {
                    if (!stat && !st) {
                        res++
                        stat = true;
                    }
                    res = res + t;
                }
            }
        }
        if (st) res++; 
        //cerr << u << " " << st << " " << res << '\n';
        return res;
    };
    cout << DFS(x , x , DFS); 
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