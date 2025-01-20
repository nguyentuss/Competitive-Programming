#include <bits/stdc++.h>

using namespace std;

#define ii pair<int ,int>
#define int long long

const int N = 507;
const int inf = 1e18;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n , m , q; cin >> n >> m >> q;
    vector<vector<int>> d(n , vector<int>(n , inf));
    vector<vector<int>> C(n , vector<int>(n , inf));
    vector<ii> adj[N];
    set<tuple<int , int , int>> s;
    for (int i = 0 ; i < m ; i++) {
        int u , v , c; cin >> u >> v >> c;
        u--; v--; 
        if (u > v) swap(u , v);
        s.insert({u , v , c}); 
        
    }
    for (auto [u , v , c] : s) {
        adj[u].push_back(ii(c , v));
        adj[v].push_back(ii(c , u));
        C[u][v] = C[v][u] = min(C[u][v] , c);
    }
/*****DIJKSTRA****/
    auto dijkstra = [&]() -> void {
        min_heap <ii> pq;
        for (int i = 0 ; i < n ; i++) {
            pq.push(ii(0 , i));
            d[i][i] = 0;
            while (!pq.empty()) {
                auto [du , u] = pq.top(); 
                pq.pop();
                if (du != d[i][u]) continue;
                for (auto [uv , v] : adj[u]) {
                    if (du + uv < d[i][v]) {
                        d[i][v] = du + uv; 
                        pq.push(ii(d[i][v] , v));
                    }
                }
            }
        }
    };
/******FLOYD*****/
    auto floyd = [&]() -> void {
        for (int i = 0 ; i < n ; i++) C[i][i] = 0;
        for (int k = 0 ; k < n ; k++) {
            for (int i = 0 ; i < n ; i++) {
                for (int j = 0 ; j < n ; j++) {
                    C[i][j] = min(C[i][j] , C[i][k] + C[k][j]);
                }
            }
        }
        d = C;
    };
    floyd();
    while (q--) {
        int u , v; cin >> u >> v;
        u--; v--;
        if (u > v) swap(u , v);
        cout << (d[u][v] == inf ? -1 : d[u][v]) << '\n';
    }
        
    return 0;
}