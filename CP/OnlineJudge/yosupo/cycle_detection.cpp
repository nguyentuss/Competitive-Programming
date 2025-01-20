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
    vector<pii> a;
    for (int i = 0 ; i < m ; i++) {
        int u , v; cin >> u >> v;
        a.push_back({u , v});
        adj[u].push_back({v , i});
    }
    vector<int> vis(n);
    stack<int> st;
    bool ok = true;
    int t = -1;
    vector<int> finish(n);
    function<bool(int)> DFS = [&](int u) {
        vis[u] = true;
        for (auto [v,id] : adj[u]) {
            st.push(id);
            if (!vis[v]) {
                if (DFS(v)) return true;
            }
            if (vis[v] == 1) {
                t = v; 
                return true;
            }
            st.pop();
        }
        vis[u] = 2;
        return false;
    };

    for (int i = 0 ; i < n ; i++) {
        if (vis[i]) continue;
        DFS(i);
        vi ans;
        while (!st.empty()) {
            int id = st.top(); 
            auto [x , y] = a[id];
            ans.push_back(id);
            st.pop();
            if (x == t) break;
        }
        if (sz(ans) == 0) continue;
        cout << sz(ans) << '\n';
        reverse(all(ans));
        for (int x : ans) cout << x << '\n';
        return;
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
