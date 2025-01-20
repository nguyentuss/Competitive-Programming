#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (300007)

int n , m; 
char a[MAX_N];
bool vis[MAX_N];
vector <int> g;

void DFS(int u) {
    vis[u] = 2;
    for (auto v : adj[u]) {
        if (!vis[v]) {
            DFS(v);
        }
    }
    g.push_back(u);
    vis[u] = 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1 ; i <= n ;i ++) cin >> a[i];
    DFS(1 , -1);
    for (auto u : g) {
        for (v : adj[u]) {
                
        }
    }
    return 0;
}