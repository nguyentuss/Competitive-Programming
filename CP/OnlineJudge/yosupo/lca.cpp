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

struct LCA {
    int n; 
    vector<vi> adj;
    vi siz; 
    vi h;
    vector<vi> P;
    vi pre;

    LCA(int n): n(n), adj(n), siz(n), h(n), P(n , vi(22,-1)), pre(n) {}
    void init() {
        preDFS(0, -1);
        for (int k = 1 ; k < 22 ; k++) {
            for (int i = 0 ; i < n ; i++) {
                if (P[i][k - 1] != -1) {
                    P[i][k] = P[P[i][k - 1]][k - 1];
                }
            }
        }
    }

    void addEdge(int u , int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void preDFS(int u , int father) {
        P[u][0] = father;
        for (int v : adj[u]) {
            if (v != father) {
                h[v] = h[u] + 1;
                preDFS(v , u);
            }
        }
    }
    
    int calc(int u , int v) {
        // cerr << u << ' ' << v << ' ' << h[u] << ' ' << h[v] << '\n';
        if (h[u] < h[v]) swap(u , v);
        // cout << u << ' ' << v << ' ';
                // cerr << u << ' ' << v << ' ' << k << '\n';
        if (h[u] != h[v]) {
            for (int k = 21 ; k >= 0 ; k--) {
                if (P[u][k] != -1 && h[P[u][k]] >= h[v]) {
                    u = P[u][k];
                }
            }
        }
        // cout << u << ' ' << v << '\n';
        if (u == v) return u;
        for (int k = 21 ; k >= 0 ; k--) {
            if (P[u][k] != -1 && P[v][k] != -1 && P[u][k] != P[v][k]) {
                u = P[u][k]; 
                v = P[v][k];
            }
        }
        return P[u][0];
    }

};

void solve() {
    int n , q; cin >> n >> q;
    LCA lca(n);
    for (int i = 1 ; i < n ; i++) {
        int p; cin >> p;
        lca.addEdge(i , p);
    }
    lca.init();
    while (q--) {
        int u , v; cin >> u >> v;
        cout << lca.calc(u , v) << '\n';
    }
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
