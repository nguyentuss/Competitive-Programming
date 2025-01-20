//source:: https://codeforces.com/contest/1900/problem/E
#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e9 + 7;

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


int nComps[N];
vector<int> b[N];
ii f[N];
int d[N];
int total[N];

void init(int n) {
    for (int i = 0 ; i < n ; i++) {
        d[i] = 0;
        total[i] = 0;
        b[i].clear();
        nComps[i] = 0;
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test; 
    cin >> test;
    while (test--) {
        int n, m; cin >> n >> m;
        init(n); 
        vector<vector<int>> g(n);
        for (int i = 0 ; i < n ; i++) cin >> d[i];
        set<ii> s;
        for (int i = 0 ; i < m ; i++) {
            int u , v; cin >> u >> v;
            u--; v--; 
            s.insert({u , v});
            g[u].push_back(v);
        }
        scc(g , [&](vi cp){});
        for (int i = 0 ; i < n ; i++) 
            nComps[comp[i]]++;
        for (auto [u , v] : s) {
            if (comp[u] == comp[v]) continue;;
            if (comp[u] < comp[v]) swap(v , u);
            b[comp[u]].push_back(comp[v]);
        }
        for (int i = 0 ; i < n ; i++) {
            total[comp[i]] += d[i];
        }
        int id_scc = 0;
        for (int i = 0 ; i < n ; i++) {
            int u = comp[i]; 
            f[u] = ii(nComps[u] , total[u]);
            id_scc = max(id_scc , comp[i]);
        }
        for (int i = id_scc ; i >= 0; i--) {
            int u = i;
            for (auto v : b[u]) {
                if ((f[u].fi + nComps[v]) > f[v].fi) {
                    f[v].fi = f[u].fi + nComps[v];
                    f[v].se = f[u].se + total[v];
                }
                else if ((f[u].fi + nComps[v]) == f[v].fi) {
                    if (f[v].se > f[u].se + total[v]) {
                        f[v].se = f[u].se + total[v];
                    }
                }
            }
        }
        ii res = ii(0 , 0);
        for (int i = 0 ; i < n ; i++) {
            if (res.fi < f[i].fi) {
                res = f[i];
            }
            else if (res.fi == f[i].fi) {
                if (res.se > f[i].se) {
                    res = f[i];
                }
            }
        }
        cout << res.fi << " " << res.se << '\n';
    }
    return 0;
}