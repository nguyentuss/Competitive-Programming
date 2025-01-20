    #include <bits/stdc++.h>

    using namespace std;

    #define MOD (int) (1e9 + 7) 
    #define MAX_N (int) (1e5 + 7)

    int n , m;
    vector<int> adj[MAX_N];
    int vis[MAX_N];
    vector<int> a;
    int f[MAX_N];

    void DFS(int u) {
        vis[u] = 1;
        for (auto v : adj[u]) {
            if (!vis[v]) {
                DFS(v);
            }
        }
        a.push_back(u);
        vis[u] = 2;
        return;
    }

    int main() {
        ios::sync_with_stdio(0); cin.tie(NULL);
        cout.tie(NULL);
        cin >> n >> m;
        for (int i = 1 ; i <= m ; i++) {
            int u , v; cin >> u >> v;
            adj[u].push_back(v);
        }
        for (int i = 1 ; i <= n ; i++) {
            if (!vis[i]) {
                DFS(i);
            }
        }
        reverse(a.begin() , a.end());
        f[1] = 1;
        for (auto u : a) {
            for (auto v : adj[u]) {
                (f[v] += f[u])%=MOD;
            }
        }
        cout << f[n];
        return 0;
    }