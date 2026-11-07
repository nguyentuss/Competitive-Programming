#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
typedef pair<int, int> ii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;


void solve() {  
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> ops(n+1);
    for (int i = 0 ; i < m ; i++) {
        int x; cin >> x;
        ops[x] = 1;
    }
    vector<bool> vis(n + 1);
    int ans = 0; 
    auto dfs = [&](auto &dfs, int u, int sum) -> void {
        vis[u] = 1;
        if (u == 1) return; 
        if (ops[u]) {
            ans = max(ans, 1 + sum);
        }
        for (int v : adj[u]) {
            if (!vis[v]) {
                if (v == 1) {
                    ans = max(ans, 1 + sum);
                }
                dfs(dfs, v, sum + 1);
            }
            
        }
    };
    dfs(dfs, n, 0); 
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
