#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (2e5 + 7)
#define inf (int) (1e9 + 7)
#define ii pair<int , int>
#define f first
#define s second

int n , m;
int d[MAX_N] , f[MAX_N];
vector<int> adj[MAX_N];
bool vis[MAX_N];

void DFS(int u) {
    vis[u] = true;
    f[u] = min(f[u] , d[u]);
    for (auto v : adj[u]) {
        if (!vis[v] && d[u] < d[v]) {
            DFS(v);
        }
        if (d[u] < d[v]) {
            f[u] = min(f[u] , f[v]);
        }
        else f[u] = min(f[u] , d[v]);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1 ; i <= n ; i++) {
            adj[i].clear();
            vis[i] = 0;
            f[i] = d[i] = inf;
        }
        d[1] = 0;
        for (int i = 1 ; i <= m ; i++) {
            int u , v; cin >> u >> v;
            adj[u].push_back(v);
        }
        priority_queue<ii , vector<ii> , greater<ii>> pq;
        pq.push(ii(0 , 1));
        while (!pq.empty()) {
            int u = pq.top().s;
            pq.pop();
            for (auto v : adj[u]) {
                if (d[v] > (d[u] + 1)) {
                    d[v] = d[u] + 1;
                    pq.push(ii(d[v] , v));
                }
            }
        }   
        f[1] = 0;
        DFS(1);
        for (int i = 1 ; i <= n ; i++) cout << f[i] << " ";
        cout << '\n';
    }

    return 0;
}