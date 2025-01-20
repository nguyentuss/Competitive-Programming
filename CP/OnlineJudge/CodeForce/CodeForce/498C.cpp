    //#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll inf = 1e18;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

/**
 * Author: chilli
 * Date: 2019-04-26
 * License: CC0
 * Source: https://cp-algorithms.com/graph/dinic.html
 * Description: Flow algorithm with complexity O(VE\log U)$ where U = \max |\text{cap}|$.
 * O(\min(E^{1/2}, V^{2/3})E)$ if U = 1$; O(\sqrt{V}E)$ for bipartite matching.
 * Status: Tested on SPOJ FASTFLOW and SPOJ MATCHING, stress-tested
 */

struct Dinic {
    struct Edge {
        int to, rev;
        ll c, oc;
        ll flow() { return max(oc - c, 0LL); } // if you need flows
    };
    vi lvl, ptr, q;
    vector<vector<Edge>> adj;
    Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
    void addEdge(int a, int b, ll c, int rcap = 0) {
        adj[a].push_back({b, sz(adj[b]), c, c});
        adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});
    }
    ll dfs(int v, int t, ll f) {
        if (v == t || !f) return f;
        for (int& i = ptr[v]; i < sz(adj[v]); i++) {
            Edge& e = adj[v][i];
            if (lvl[e.to] == lvl[v] + 1)
                if (ll p = dfs(e.to, t, min(f, e.c))) {
                    e.c -= p, adj[e.to][e.rev].c += p;
                    return p;
                }
        }
        return 0;
    }
    ll calc(int s, int t) {
        ll flow = 0; q[0] = s;
        rep(L,0,31) do { // 'int L=30' maybe faster for random data
            lvl = ptr = vi(sz(q));
            int qi = 0, qe = lvl[s] = 1;
            while (qi < qe && !lvl[t]) {
                int v = q[qi++];
                for (Edge e : adj[v])
                    if (!lvl[e.to] && e.c >> (30 - L))
                        q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
            }
            while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
        } while (lvl[t]);
        return flow;
    }
    bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

const int N = 1e2 + 7;

int idx = 0;

vector<tuple<int , int , int>> a[N];

vector<tuple<int , int , int>> numberFactor(int x) {
    vector<tuple<int , int , int>> tmp;
    for (int i = 2 ; i * i <= x ; i++) {
        if (x % i == 0) {
            int cnt = 0;
            while (x % i == 0) {
                cnt++; 
                x /= i;
            }
            tmp.push_back(make_tuple(++idx , i , cnt));
        }    
    }
    if (x > 1) {
        tmp.push_back(make_tuple(++idx , x , 1));
    }
    return tmp;
}

void solve() {
    int n, m; cin >> n >> m; 
    for (int i = 1 ; i <= n ; i++) {
        int x; cin >> x;
        a[i] = numberFactor(x);
    }
    int s = 0 , t = idx + 1;
    Dinic D = Dinic(idx + 7);
    for (int i = 1 ; i <= n ; i += 2) {
        for (auto x : a[i]) {
            D.addEdge(s , get<0>(x) , get<2>(x));

        }
        //cerr << 0 << " " << i << " " << inf << '\n';
    }
    for (int i = 2 ; i <= n ; i += 2) {
        for (auto x : a[i]) {
            D.addEdge(get<0>(x) , t , get<2>(x));

        }
        //cerr << i << " " << n + 1 << " " << inf << '\n';
    }

    for (int i = 0 ; i < m ; i++) {
        int x , y; cin >> x >> y;
        if (!(x % 2)) {
            swap(x , y);
        }
        for (auto u : a[x]) {
            for (auto v : a[y]) {
                if (get<1>(u) == get<1>(v)) {
                    D.addEdge(get<0>(u) , get<0>(v) , min(get<2>(u) , get<2>(v)));
                }
            }
        } 
        //cerr << g << '\n';
    }
    cout << D.calc(s , t);
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
