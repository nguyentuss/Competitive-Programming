#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MAX_N (int) (1e5 + 7)

int n , m;  
vector<int> adj[MAX_N];
vector<bool> vis(MAX_N , false);

void DFS(int u) {
    vis[u] = true;
    for (auto v : adj[u]) {
        if (!vis[v]) {
            DFS(v);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1 ; i <= m ; i++) {
        int u , v ; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> v;
    int ans = 0;
    for (int i = 1 ; i <= n ; i++) {
        if (!vis[i]) {
            ans++;
            v.push_back(i);
            DFS(i);
        }
    }
    cout << ans - 1 << '\n';
    for (int i = 0 ; i < (v.size() - 1) ; i++) {
        cout << v[i] << " " << v[i + 1] << '\n';
    }
    return 0;
}