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
const int MOD = 1e18 + 7;

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

/**
 * Author: Unknown
 * Date: 2002-09-13
 * Source: predates tinyKACTL
 * Description: Topological sorting. Given is an oriented graph.
 * Output is an ordering of vertices, such that there are edges only from left to right.
 * If there are cycles, the returned list will have size smaller than n$ -- nodes reachable
 * from cycles will not be returned.
 * Time: O(|V|+|E|)$
 */
#pragma once

vi topoSort(const vector<vi>& gr) {
    vi indeg(sz(gr)), ret;
    for (auto& li : gr) for (int x : li) indeg[x]++;
    queue<int> q; // use priority queue for lexic. smallest ans.
    rep(i,0,sz(gr)) if (indeg[i] == 0) q.push(-i);
    while (!q.empty()) {
        int i = -q.front(); // top() for priority queue
        ret.push_back(i);
        q.pop();
        for (int x : gr[i])
            if (--indeg[x] == 0) q.push(-x);
    }
    return ret;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n); 
    for (int i = 0; i < m; i ++) {
        int u, v; cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
    }
    scc(g, [&](vi cp){});
    vector<int> a(ncomps); 
    vector<vector<int>> adj(ncomps);
    map<pair<int , int> , bool> mp; 
    for (int u = 0 ; u < n ; u++) {
        for (int v : g[u]) {
            if (comp[u] != comp[v] && mp[pii(comp[u] , comp[v])] == false) {
                adj[comp[u]].push_back(comp[v]);
                mp[pii(comp[u] , comp[v])] = true;
            }
        }
    }
    vector<vector<int>> list_ver_scc(ncomps);
    for (int i = 0 ; i < n ; i++) {
        list_ver_scc[comp[i]].push_back(i);
    }
    //cerr << "DEBUG";
    vi ans = topoSort(adj);
    int fn = ans[sz(ans) - 1];
    cout << list_ver_scc[fn].size() << '\n';
    sort(list_ver_scc[fn].begin() , list_ver_scc[fn].end()); 
    for (int x : list_ver_scc[fn]) {
        cout << x + 1 << " ";
    }

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