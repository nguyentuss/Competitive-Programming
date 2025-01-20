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
const int inf = 1e18;

struct SP {
    int n; 
    vector<vector<pii>> adj;
    vector<int> d;
    vector<int> trace;

    SP(int n): n(n), adj(n), d(n), trace(n) {
        init();
    }

    void addEdge(int u , int v , int w) {
        adj[u].push_back({w , v});
        // adj[v].push_back({w , u});
    }

    void init() {
        for (int i = 0 ; i < n ; i++) {
            d[i] = inf;
            trace[i] = -1;
        }
    }

    int dist(int s , int t) {
        min_heap<pii> pq;
        init();
        pq.push({0 , s});
        d[s] = 0;
        while (!pq.empty()) {
            auto [du , u] = pq.top();
            pq.pop();
            if (du != d[u]) continue;
            for (auto [w , v] : adj[u]) {
                if (d[v] > d[u] + w) {
                    trace[v] = u;
                    d[v] = d[u] + w; 
                    pq.push({d[v] , v});
                }
            }
        }
        return d[t];    
    }

    void back(int s , int t) {
        vector<int> path; 
        for (int p = t; p != -1 ; p = trace[p]) path.push_back(p);
        cout << d[t] << ' ' << sz(path) - 1 << '\n';
        reverse(all(path));
        for (int i = 0 ; i < sz(path) - 1 ; i++) {
            cout << path[i] << ' ' << path[i + 1] << '\n';
        }
    }
};

void solve() {
    int n, m, s , t; cin >> n >> m >> s >> t;
    SP sp(n);
    for (int i = 0 ; i < m ; i++) {
        int u , v , w; cin >> u >> v >> w; 
        sp.addEdge(u , v, w);
    }
    if (sp.dist(s , t) == inf) {
        cout << -1 << '\n';
    }
    else {
        sp.back(s , t);
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
