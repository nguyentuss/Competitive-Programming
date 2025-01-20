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

struct Dinic {
    int n;
    vector<vi> adj; 
    vector<vi> resi;
    vector<vi> aug; 
    vi level;
    int s , t;

    Dinic(int n , vector<vi> adj_ , vector<vi> resi_, int s , int t): n(n), adj(adj_), resi(resi_), aug(n,vi(n)), level(n), s(s), t(t) {}

    void BFS() {
        level.assign(n , 0);
        queue<int> q;
        q.push(s);
        level[s] = 1;
        while (!q.empty()) {
            int u = q.front(); 
            q.pop();
            for (int v : adj[u]) {
                if (!level[v] && (resi[u][v] || aug[u][v])) {
                    level[v] = level[u] + 1;
                    q.push(v);
                }   
            }
        }
    }

    int DFS(int u , int d) {
        if (u == t) return d;
        int ans = 0;
        for (int v : adj[u]) {
            if (level[v] == level[u] + 1) {
                if (resi[u][v]) {
                    ans = DFS(v , min(d , resi[u][v]));
                    if (ans != 0) {
                        resi[u][v] -= ans; 
                        aug[v][u] += ans;
                        return ans;
                    }
                }
                if (aug[u][v]) {
                    ans = DFS(v , min(d , aug[u][v]));
                    if (ans != 0) {
                        aug[u][v] -= ans; 
                        resi[v][u] += ans;
                        return ans;
                    }
                }
            }
        }
        return ans;
    }

    int calc() {
        int flow = 0;
        while (true) {
            BFS();
            if (level[t] == 0) break;
            while (int x = DFS(s , inf)) {
                flow += x;
            }
        }
        return flow;
    }

};

void solve() {
    int n , m , s , t; cin >> n >> m >> s >> t; 
    s--; t--;
    vector<vi> adj(n);
    vector<vi> resi(n , vi(n));
    for (int i = 0 ; i < m ; i++) {
        int u , v , w; cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back(v); 
        adj[v].push_back(u);
        resi[u][v] += w;
    }
    Dinic f(n , adj, resi, s , t);
    cout << f.calc();
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
