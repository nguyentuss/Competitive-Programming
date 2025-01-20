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
const int mod = 998244353;

void solve() {
    int n , m; cin >> n >> m;
    vector<vi> adj(n);
    for (int i = 0 ; i < m ;i ++) {
        int u , v; cin >> u >> v;
        u--; v--; 
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    vector<int> vis(n);
    vector<int> c(n);
    vector<int> trace;
    auto DFS = [&](int u , auto &&DFS) -> bool {
        vis[u] = true;
        trace.push_back(u); 
        for (int v : adj[u]) {
            if (!vis[v]) {
                c[v] = c[u] ^ 1; 
                if (!DFS(v , DFS)) return false;
            }
            else {
                if (c[v] == c[u]) {
                    return false;
                }
            }
        }
        return true;
    };
    int ans = 1;
    for (int i = 0 ; i < n ; i++) {
        if (vis[i]) continue;
        if (DFS(i ,  DFS)) {
            int a = 1 , b = 1;
            for (int j : trace) {
                if (!c[j]) (a *= 2)%=mod; 
                else (b *= 2)%=mod;
            }
            if (sz(trace) == 1) {
                (ans *= 3)%=mod;
            }
            else ans = (ans*(a + b)%mod)%mod;
        }
        else {
            cout << 0 << '\n';
            return;
        }
        trace.clear();
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