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
const int mod = 1e9 + 7;

int pow(int a , int b) {
    if (b == 0) return 1;
    int child = pow(a , b/2)%mod;
    int x = (child*child)%mod;
    if (b & 1) return (x*a)%mod; 
    return x%mod;
}

void solve() {
    int n; cin >> n;
    vector<vector<int>> g(n);
    for (int i = 1 ; i < n ;i ++) {
        int u , v; cin >> u >> v;
        // cerr << u << ' ' << v << '\n';
        g[v].push_back(u);
    }
    vector<bool> vis(n); 
    vector<int> topo;
    function<void(int)> dfs = [&](int u) {
        vis[u] = true;
        for (int v : g[u]) {
            if (!vis[v]) 
            dfs(v);
        }
        topo.push_back(u);
    };
    for (int i = 0 ; i < n ; i++) if (!vis[i]) dfs(i);  
    reverse(all(topo));
    for (int x : topo) cout << x << ' ';
    z

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
