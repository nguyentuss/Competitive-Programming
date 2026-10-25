#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (2e5 + 7)

int n , m;
vector<int> adj[MAX_N];
int vis[MAX_N];
bool cycle;

void dfs(int u) {
    vis[u] = 2;
    for (auto v : adj[u]) {
        if (!vis[v]) dfs(v);
        else if (vis[v] == 2) {
            cycle = true;
        }  
    }
    vis[u] = 1;
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
        }
        cycle = false;
        for (int i = 1 ; i <= m ; i++) {
            int u , v; cin >> u>> v;
            adj[u].push_back(v);
        }
        for (int i = 0 ; i <= n ;i++) 
            if (!vis[i]) dfs(i);
        cout << (cycle == true ? 1 : 0) << '\n';
    }
    return 0;
}