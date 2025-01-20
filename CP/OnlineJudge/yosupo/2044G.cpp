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

struct SCC {
    int n;
    vector<vi> ls , g, adj;
    vi low, num, p;
    vector<pii> Edge; 
    int timeDFS = 0;
    stack<int> s;
    int scc = 0;

    SCC(int n): n(n), low(n), num(n), ls(n), g(n), adj(n), p(n){}

    void addEdge(int u , int v) {
        adj[u].push_back(v);
        Edge.push_back({u , v});
    }

    void DFS(int u) {
        low[u] = num[u] = ++timeDFS;
        s.push(u); 
        for (int v : adj[u]) {
            if (!num[v]) {
                DFS(v);
                low[u] = min(low[u] , low[v]);
            }
            else {
                low[u] = min(low[u] , num[v]);
            }
        }
        if (low[u] == num[u]) {
            while (s.top() != u) {
                p[s.top()] = scc;
                // cerr << s.top()+1 << ' ' << scc << '\n';
                ls[scc].push_back(s.top());
                low[s.top()] = num[s.top()] = inf;
                s.pop();
            }
            // cerr << s.top()+1 << ' ' << scc << '\n';
            p[s.top()] = scc;
            ls[scc++].push_back(s.top());
            low[s.top()] = num[s.top()] = inf;
            s.pop();
        }
    }

    void calc() {
        for (int i = 0 ; i < n ; i++) {
            if (!num[i]) {
                DFS(i);
            }
        }
        for (auto [u , v] : Edge) {
            if (p[u] == p[v]) continue; 
            g[p[u]].push_back(p[v]);
        }
    }
};

void solve() {
    int n; cin >> n;
    vi a(n); 
    SCC scc(n);
    vector<vi> adj(n);
    for (int i = 0 ; i < n ;i ++) {
        int x; cin >> x;
        x--;
        scc.addEdge(i , x);
        adj[i].push_back(x);
    }
    scc.calc();
    vector<vi> g = scc.g;

    //------- topo
    vi vis(n);
    vi topo;
    function<void(int)> toposort = [&](int u) {
        vis[u] = true;
        for (int v : g[u]) {
            if (!vis[v]) {
                toposort(v);
            }
        }
        topo.push_back(u);
    }; 
    
    for (int i = 0 ; i < scc.scc ; i++) {
        if (!vis[i]) toposort(i);
    }
    reverse(all(topo));
    
    vi dp(n , 1);
    vis.assign(n,0);
    for (int x : topo) {
        cerr << x << ' ';
        for (int u : scc.ls[x]) {
            for (int v : adj[u]) {
                if (scc.p[u] == scc.p[v]) continue;
                if (sz(scc.ls[scc.p[v]]) > 1) {
                    dp[v] = max(dp[v] , dp[u] + 1);
                }
                else dp[v] += dp[u];
            }
        }
    }
    int ans = 0;
    for (int i = 0 ; i < n ; i++) {
        // cout << dp[i] << ' ';
        ans = max(ans , dp[i]);
    }
    cout << ans + 1 << '\n';
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
