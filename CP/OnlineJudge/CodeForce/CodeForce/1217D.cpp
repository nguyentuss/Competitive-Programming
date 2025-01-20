#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 5e3 + 7;
const int MOD = 1e9 + 7;

int d[N];
int vis[N];
vector<int> adj[N];
bool status = false;
int g[N][N];
vector<ii> vv;
void DFS(int u) {
    vis[u] = 1;
    for (auto v : adj[u]) {
        if (vis[v] == 1) {
            status = true;
            g[u][v] = 1;
            d[v] = 2;
        }
        if (!vis[v]) {
            DFS(v);
        }
    }
    vis[u] = 2;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n , m; cin >> n >> m;
    for (int i = 1 ; i <= m ;i ++) {
        int u , v; cin >> u >> v;
        adj[u].push_back(v);
        vv.push_back(ii(u , v));
    }
    for (int i = 1 ; i <= n ;i ++) {
        if (!vis[i]) DFS(i);
    }
    if (!status) {
        cout << 1 << '\n';
        for (int i = 0 ; i < m ;i ++) {
            cout << 1 << " ";
        }
    }
    else {
        cout << 2 << '\n';
        for (int i = 0 ; i < m ;i ++) {
            if (g[vv[i].fi][vv[i].se]) {
                cout << 2 << " ";
            }
            else cout << 1 << " ";
        }
    }
    return 0;
}