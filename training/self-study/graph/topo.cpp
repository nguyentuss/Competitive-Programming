#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (2e5 + 7)

int n , m;
vector<int> adj[MAX_N];
int vis[MAX_N];
int cnt = 0;
vector<int> v;

void dfs(int u) {
    vis[u] = 2;
    for (auto v : adj[u]) {
        if (!vis[v]) dfs(v);
    }
    v.push_back(u);
    vis[u] = 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1 ; i <= m ; i++) {
        int u , v; cin >> u>> v;
        adj[u].push_back(v);
    }
    for (int i = 0 ; i <= n ;i++) 
        if (!vis[i]) dfs(i);
    reverse(v.begin() , v.end());
    for (auto x : v) cout << x << " ";
    return 0;
}