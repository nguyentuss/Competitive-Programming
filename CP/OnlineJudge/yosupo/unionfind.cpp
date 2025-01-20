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

struct DSU {
    int n;
    vi p , siz;
    DSU(int n): n(n), p(n), siz(n) {
        for (int i = 0 ; i < n ; i++) {
            p[i] = i;
            siz[i] = 1;
        }
    }

    int findRoot(int u) {
        return u == p[u] ? u : findRoot(p[u]);
    }

    void Union(int u , int v) {
        u = findRoot(u); 
        v = findRoot(v);
        if (u != v) {
            if (siz[u] < siz[v]) swap(u , v);
            siz[u] += siz[v];
            p[v] = u;
        }
    }
    
    bool check(int u , int v) {
        u = findRoot(u);
        v = findRoot(v);
        return (u == v);
    }

};

void solve() {
    int n, q; cin >> n >> q;
    DSU dsu(n);
    while (q--) {
        int t , u , v; cin >> t >> u >> v; 
        if (t == 1) {
            cout << dsu.check(u , v) << '\n';
        }
        else dsu.Union(u , v);
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
