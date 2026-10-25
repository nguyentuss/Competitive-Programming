#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MAX_N (int) (107)
#define ii pair<int , int>
const int inf = 1e9 + 7;

int bomb[MAX_N];
vector<ii> adj[MAX_N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    int n , m , s , t; cin >> n >> m >> s >> t;
    for (int i = 1 ; i <= n ; i++) {
        cin >> bomb[i];
    }    
    for (int i = 1 ; i <= m ; i++) {
        int u , v , w; cin >> u >> v >> w;
        adj[u].push_back(ii(v , w));
        adj[v].push_back(ii(u , w));
    }
    priority_queue<ii , vector<ii> , greater<ii>> pq;
    vector<int> d(n + 1 , inf);
    pq.push(ii(0 , s));
    d[s] = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (auto x : adj[u]) {
            int v = x.first;
            int w = x.second;
            if (d[v] > d[u] + w) {
                if (bomb[v] && d[u] + w < bomb[v]) {
                    d[v] = d[u] + w;
                    pq.push(ii(d[v] , v));  
                }
                else if (!bomb[v]) {
                    d[v] = d[u] + w;
                    pq.push(ii(d[v] , v));
                }
            }
        }
    }
    if (d[t] == inf) cout << -1;
    else cout << d[t];

    return 0;
}