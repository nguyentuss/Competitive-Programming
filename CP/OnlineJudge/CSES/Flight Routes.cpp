#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ii pair<int , int>

const int N = 1e5 + 7;
const int inf = 1e18;

int n, m , k;
vector<ii> adj[N];
priority_queue<int> best[N];
vector<int> res;

// find shortest path > 
void dijkstra() {
    priority_queue<ii , vector<ii> , greater<ii>> pq;
    vector<int> d(n , inf);
    vector<int> vis(n);
    d[0] = 0; pq.push(ii(0 , 0));
    while (!pq.empty()) {
        auto [du , u] = pq.top(); 
        pq.pop();
        if (vis[u] >= k) continue;
        if (u == (n - 1)) res.push_back(du);
        vis[u]++;
        for (auto [v , uv] : adj[u]) {
            d[v] = du + uv;
            if (vis[v] < k) {
                pq.push(ii(d[v] , v));
            }
        }
    }
}

void solve() {
    cin >> n >> m >> k;
    for (int i = 0 ; i < m ; i++) {
        int u , v , c; cin >> u >> v >> c;
        u--; v--;
        adj[u].push_back(ii(v , c));
    }
    dijkstra();
    sort(res.begin() , res.end());
    for (auto x : res) cout << x << " ";
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}