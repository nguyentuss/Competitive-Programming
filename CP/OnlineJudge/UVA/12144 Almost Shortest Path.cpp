//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
const int inf = 1e9;

void solve() {
    int n, m; 
    while (cin >> n >> m && n) {
        vector<int> a(n) , d(n , inf);
        vector<bool> del(m , 0);
        vector<vector<tuple<int , int , int>>> adj(n) , g(n);
        int s , t; cin >> s >> t;
        for (int i = 0 ; i < m ; i++) {
            int u , v , w; cin >> u >> v >> w;
            adj[u].emplace_back(v , w , i);
            g[v].emplace_back(u , w , i);
            //adj[v].emplace_back(u , w , i);
        }
        auto dijsktra = [&](bool stat) -> int {
            d.assign(n , inf);
            d[s] = 0;
            min_heap<pii> pq; 
            pq.push(pii(0 , s));
            while (!pq.empty()) {
                auto [du , u] = pq.top();
                pq.pop();
                if (d[u] != du) continue; 
                for (auto [v , w , id] : adj[u]) {
                    if (stat) {
                        if (d[v] > du + w) {
                            d[v] = du + w; 
                            pq.push(pii(d[v] , v));
                        }
                    }
                    else {
                        if (!del[id] && d[v] > d[u] + w) {
                            d[v] = d[u] + w; 
                            pq.push(pii(d[v] , v));
                        }
                    }
                }
            }
            return d[t];
        };
        auto backtrack = [&]() -> void {
            queue<int> q; 
            q.push(t); 
            vector<int> vis(n , false);
            vis[t] = true;
            while (!q.empty()) {
                int u = q.front();
                q.pop(); 
                for (auto [v , w , id] : g[u]) {
                    if (!vis[v] && d[v] + w == d[u]) {
                        vis[v] = true; 
                        del[id] = true;
                        //cerr << v << '\n';
                        q.push(v);
                    }
                }
            }
        };
        dijsktra(1);
        backtrack();
        int c = dijsktra(0);
        cout << (c == inf ? -1 : c) << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test; 
    test = 1;
    //cin >> test;
    while (test--) {
        solve();
    }

}