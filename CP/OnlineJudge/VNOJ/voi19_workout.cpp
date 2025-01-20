#include <bits/stdc++.h>
 
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
 
#define ii pair<int , int>
#define f first
#define s second
#define int long long
const int inf = 1e18 + 7;
const int MAX_N = 2e5 + 7;
const int MOD = 1e9 + 7;

vector<ii> adj[MAX_N];
vector<ii> g[MAX_N];   

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n , m , k; cin >> n >> m >> k;
    for (int i = 1 ; i <= m ; i++) {
        int u , v , w; cin >> u >> v >> w;
        adj[u].push_back(ii(v , w));
        adj[v].push_back(ii(u , w));
    }    
    function <vector<int>(int)> dijkstra = [&](int a) {
        priority_queue<ii , vector<ii> , greater<ii>> pq;
        vector<int> dist(n + 1 , inf);
        pq.push(ii(0 , a));
        dist[a] = 0;
        while (!pq.empty()) {
            int u = pq.top().s;
            int du = pq.top().f;
            pq.pop();
            for (auto x : adj[u]) {
                int v = x.f;
                int w = x.s;
                if (dist[v] > du + w) {
                    dist[v] = du + w;
                    pq.push(ii(dist[v] , v));
                }
            } 
        }
        return dist;
    };

    int p , a , b; cin >> a >> b;
    int tmp = b;
    vector<int> d_t1 = dijkstra(a) , d_tn = dijkstra(b);
    cin >> p >> a >> b;
    vector<int> d_fr = dijkstra(a) , d_frn = dijkstra(b);
    queue<int> q; vector<int> vis(n + 1 , 0);
    // for (int i = 1 ; i <= n ; i++) {
    //     cout << d_t1[i] << " ";
    // }
    // cout << '\n';
    // for (int i = 1 ; i <= n ; i++) {
    //     cout << d_fr[i] << " ";
    // }
    // cout << '\n';
    q.push(a);
    vis[a] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto x : adj[u]) {
            int v = x.f;
            int w = x.s;
            if (d_fr[v] == (d_fr[u] + w)) {
                g[u].push_back(ii(v , w));
                //cerr << u << " " << v << " " << w << '\n';
            }
            if (!vis[v]) {
                
                vis[v] = true;
                q.push(v);  
            }
        }
    }
    vis.assign(n + 1 , 0);
    // for (int i = 1 ; i <= n ; i++) {
    //     cout << i << ": ";
    //     for (auto x : g[i]) {
    //         cout << x.first << " ";
    //     }
    //     cout << '\n';
    // }
    vector<int> topo;
    function <void(int)> DFS = [&](int u) {
        vis[u] = 1;
        for (auto x : g[u]) {
            int v = x.f;
            if (!vis[v]) {
                DFS(v);
            }
        }
        topo.push_back(u);
        vis[u] = 2;
    };
    for (int i = 1 ; i <= n ;i ++) {
        if (!vis[i]) DFS(i);
    }
    reverse(topo.begin() , topo.end());
    // for (auto u : topo) cout << u << " ";
    //  cout << '\n';
    vector<vector<int>> f(vector<vector<int>> (n + 1 , vector<int>(2 , 0)));
    for (auto u : topo) {
        if ((d_t1[u] + d_tn[u] != d_t1[tmp]) || (d_fr[u] + d_frn[u] != d_fr[b])) continue;  
        for (auto x : g[u]) {
            int v = x.f;
            int w = x.s;
            if (d_t1[u] == d_fr[u]) {
                f[v][0] = max(f[v][0] , f[u][0] + w);
            }   
            else if (p && d_t1[u] != d_fr[u]) {
                f[v][1] = max(f[v][1] , f[u][1] + w);
            }
        }
    }
    int ans = 0;
    if (p) {
        for (int i = 1 ; i <= n ; i++) {
            if (((d_t1[i] + d_tn[i]) == d_t1[tmp]) && ((d_fr[i] + d_frn[i]) == d_fr[b])) {
                ans = max({ans , f[i][0] , f[i][1]});
            }
        }
    }
    else {
        for (int i = 1 ; i <= n ; i++) {
            if (((d_t1[i] + d_tn[i]) == d_t1[tmp]) && ((d_fr[i] + d_frn[i]) == d_fr[b])) {
                ans = max(ans , f[i][0]);
            }
        }
    }
    cout << ans;
    return 0;
}