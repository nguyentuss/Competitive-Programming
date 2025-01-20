#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ii pair<int , int>
#define sz(x) (int)x.size()

const int N = 1e5 + 7;
const int inf = 1e18;
const int MOD = 1e9 + 7;

vector<ii> adj[N];

void dijkstra(int n, int s) {
    priority_queue<ii , vector<ii> , greater<ii>> pq;
    vector<int> d(n , inf) , C(n , 0) , f_min(n , inf) , f_max(n , 0);
    pq.push(ii(0 , s)); 
    d[s] = 0; C[s] = 1;
    f_max[s] = 0; f_min[s] = 0;
    while (!pq.empty()) {
        auto [du , u] = pq.top();
        pq.pop();
        if (d[u] != du) continue;
        //cerr << du << " " << u + 1 << '\n';
        for (auto [v , uv] : adj[u]) {
            if (d[v] > (du + uv)) {
                d[v] = du + uv;
                C[v] = C[u]%MOD;
                pq.push(ii(d[v] , v));
                f_max[v] = f_max[u] + 1;
                f_min[v] = f_min[u] + 1;
            }
            else if (d[v] == (d[u] + uv)) {
                f_max[v] = max(f_max[v] , f_max[u] + 1ll); 
                f_min[v] = min(f_min[v] , f_min[u] + 1ll);
                (C[v] += C[u])%=MOD;
            }
        }
    }
    cout << d[n - 1] << " " << C[n - 1]%MOD << " " << f_min[n - 1] << " " << f_max[n - 1];
}

void solve() {
    int n , m; cin >> n >> m;
    for (int i = 0 ; i < m ; i++) {
        int u , v , c; cin >> u >> v >> c; u--;v--; 
        adj[u].push_back(ii(v , c)); 
        //adj[v].push_back(ii(u , c));
    }    
    dijkstra(n , 0);
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}