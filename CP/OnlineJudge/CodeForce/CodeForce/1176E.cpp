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
    int n , m; cin >> n >> m;
    vector<vi> adj(n); 
    for (int i = 0 ; i < m ; i++) {
        int u , v; cin >> u >> v; 
        u--; v--; 
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    vector<int> vis(n);
    vector<int> c(n);
    auto DFS = [&](int u , auto &&DFS) -> void {
        vis[u] = true; 
        for (int v : adj[u]) {
            if (!vis[v]) {
                c[v] = c[u] ^ 1; 
                DFS(v , DFS); 
            }
        }
    };
    DFS(0 , DFS);
    vector<int> ans;
    vector<int> ans1;
    for (int i = 0 ; i < n ; i++) {
        if (c[i]) ans.push_back(i + 1);
        else ans1.push_back(i + 1);
    }
    if (sz(ans) > sz(ans1)) {
        cout << sz(ans1) << '\n';
        for (int x : ans1) cout << x << " ";
        cout << '\n';
        return;
    }
    cout << sz(ans) << '\n';
    for (int x : ans) cout << x << " ";
    cout << '\n';
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