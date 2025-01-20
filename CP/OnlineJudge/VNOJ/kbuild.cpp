#include <bits/stdc++.h>

using namespace std;

#define int long long
const int MAX_N = 2e5 + 10;

vector<int> adj[MAX_N];
int low[MAX_N] , num[MAX_N];
int n , m , timeDFS = 0 , bridge = 0;

void DFS(int u , int father) {
    low[u] = num[u] = ++timeDFS;
    for (auto v : adj[u]) {
        if (v == father) continue;
        if (!num[v]) {
            DFS(v , u);
            low[u] = min(low[u] , low[v]);
            if (low[v] == num[v]) bridge++;
        }
        else low[u] =min(low[u] , num[v]);
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1 ; i < n ;i ++) {
        int u , v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> m;
    for (int i = 1 ; i <= m ; i++) {
        int u , v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1 , 1);
    cout << bridge;
    return 0;
}