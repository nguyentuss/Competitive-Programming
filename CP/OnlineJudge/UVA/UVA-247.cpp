//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;

// tag : SCC

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
    int n, m;
    int cc = 0;
    while (cin >> n >> m && n && m) {
        unordered_map<string , int> mp;
        unordered_map<int , string> revmp;
        vector<vector<int>> adj(n);
        int idx = 1;
        for (int i = 0 ; i < m ; i++) {
            string a, b; cin >> a >> b;
            if (!mp[a]) revmp[idx - 1] = a , mp[a] = idx++; 
            if (!mp[b]) revmp[idx - 1] = b , mp[b] = idx++; 
            //cerr << mp[a] << " " << mp[b] << '\n';
            adj[mp[a] - 1].push_back(mp[b] - 1);
        }
        scc(adj , [&](vi cp){});
        vector<vector<int>> ans(n);
        for (int i = 0 ; i < n ; i++) {
            //cout << comp[i] << " ";
            ans[comp[i]].push_back(i);
        }
        cc++;
        cout << "Calling circles for data set " << cc << ":\n";
        for (int i = 0 ; i < n ; i++) {
            if (ans[i].size()) {
                int cnt = 0;
                for (auto x : ans[i]) {
                    cnt++;
                    cout << revmp[x];

                    if (cnt != ans[i].size()) {
                        cout << ", ";
                    }
                }
                cout << '\n';
            }
        }
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