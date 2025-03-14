//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define int long long	
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e9 + 7;

/**
 * Author: Lukas Polacek
 * Date: 2009-10-28
 * License: CC0
 * Source: Czech graph algorithms book, by Demel. (Tarjan's algorithm)
 * Description: Finds strongly connected components in a
 * directed graph. If vertices u, v$ belong to the same component,
 * we can reach u$ from v$ and vice versa.
 * Time: O(E + V)
 * Status: Bruteforce-tested for N <= 5
 * Usage: scc(graph, [\&](vi\& v) { ... }) visits all components
 * in reverse topological order. comp[i] holds the component
 * index of a node (a component only has edges to components with
 * lower index). ncomps will contain the number of components.
 */
#pragma once

vi val, comp, z, cont;
int Time, ncomps;
template<class G, class F> int dfs(int j, G& g, F& f) {
    int low = val[j] = ++Time, x; z.push_back(j);
    for (auto e : g[j]) if (comp[e] < 0)
        low = min(low, val[e] ?: dfs(e,g,f));

    if (low == val[j]) {
        do {
            x = z.back(); z.pop_back();
            comp[x] = ncomps;
            cont.push_back(x);
        } while (x != j);
        f(cont); cont.clear();
        ncomps++;
    }
    return val[j] = low;
}
template<class G, class F> void scc(G& g, F f) {
    int n = sz(g);
    val.assign(n, 0); comp.assign(n, -1);
    Time = ncomps = 0;
    rep(i,0,n) if (comp[i] < 0) dfs(i, g, f);
}

void solve() {
    int n; cin >> n;
    vector<int> a(n); 
    for (int i = 0 ; i < n ; i++) cin >> a[i]; 
    int m; cin >> m;
    vector<vector<int>> g(n);
    for (int i = 0 ; i < m ; i++) {
        int u , v; cin >> u >> v;
        u--; v--;
        g[u].push_back(v); 
    }
    scc(g , [&](vi cp){});
    vector<int> siz(ncomps); 
    vector<int> mn(ncomps , inf);
    for (int i = 0 ; i < n ; i++) {
        mn[comp[i]] = min(mn[comp[i]], a[i]);
    }
    for (int i = 0 ; i < n ; i++) {
        if (a[i] == mn[comp[i]]) siz[comp[i]]++; 
    }
    int ans = 0; 
    int cnt = 1;
    for (int i = 0 ; i < ncomps ; i++) {
        ans += mn[i];
        (cnt *= siz[i])%=MOD;
    }
    cout << ans << " " << cnt << '\n';


}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test = 1; 
    //cin >> test; 
    while (test--) {
       solve();
    }
}