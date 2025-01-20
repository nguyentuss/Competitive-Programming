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
    vector<vector<pii>> adj(n);
    for (int i = 0 ; i < m ; i++) {
        int u , v; cin >> u >> v;
        adj[u].push_back({v , i});
        adj[v].push_back({u , i});
    }
    vi vis(n);
    vector<pii> trace(n);
    function<void(int , int)> DFS = [&](int u , int idx) {
        vis[u] = 1; 
        // cout << u << '\n';
        for (auto [v,id] : adj[u]) {
            if (id != idx) {
                trace[u] = {v , id};
                if (vis[v] == 1) {
                    int to = u;
                    int p = v;
                    vi res1, res2;
                    while (p != to) {
                        res1.push_back(p);
                        res2.push_back(trace[p].second); 
                        p = trace[p].first;
                    };
                    res1.push_back(to);
                    res2.push_back(trace[to].second);
                    cout << sz(res1) << '\n';
                    for (int x : res1) cout << x << ' '; 
                    cout << '\n';
                    for (int x : res2) cout << x << ' '; 
                    exit(0);
                }
                DFS(v , id);
                
            }
        }
        vis[u] = 2;
    };
    for (int i = 0 ; i < n ;i ++) {
        if (!vis[i]) {
            DFS(i , -1);
        }
    }
    puts("-1");
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
