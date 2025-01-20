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
    int n, m; cin >> n >> m;
    vector<vector<pii>> adj(n);
    for (int i = 0 ; i < m ; i++) {
        int u , v;
        string c; 
        cin >> u >> v >> c;
        u--; v--;
        if (c == "imposter") {
            adj[u].push_back(pii(v , 1)); 
            adj[v].push_back(pii(u , 1)); 
        }
        else {
            adj[u].push_back(pii(v , 0));
            adj[v].push_back(pii(u , 0));
        }
    }
    // f[u] = 0 -> crewmate
    // f[u] = 1 -> imposter
    vector<int> vis(n);
    vector<int> f(n,-1);
    bool ok = true;
    vector<int> trace;
    function<void(int)> DFS = [&](int u) {
        vis[u] = 1;
        trace.push_back(u);
        for (auto [v , w] : adj[u]) {
            if (!vis[v]) {
                f[v] = (f[u] + w)%2;
                DFS(v);
            }
            else if (vis[v] == 1) {
                if ((f[u] + w)%2 != f[v]) {
                    ok = false;
                }
            }
        }
        vis[u] = 2;
    };
    
    auto compute = [&]() {
        int cnt = 0;
        for (int u : trace) {
            cnt += f[u];
        }
        return cnt;
    };

    int ans = 0;
    for (int i = 0 ; i < n ; i++) {
        if (!vis[i]) {
            f[i] = 0;
            DFS(i); 
            int mx = -1;
            if (ok) mx = max(mx , compute());
            for (int x : trace) vis[x] = 0;
            trace.clear(); 
            ok = true;
            f[i] = 1; 
            DFS(i); 
            if (ok) mx = max(mx , compute());
            trace.clear();
            if (mx == -1) {
                cout << "-1 \n"; 
                return;
            }
            ans += mx;
        }
    }
    cout << ans << '\n';
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
