#include <bits/stdc++.h>

#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
const int inf = 1e9 + 7;
const int MAX_N = 1e5 + 7 ;
const int MOD = 1e9 + 7;

int f[MAX_N];
vector<int> adj[MAX_N] , g[MAX_N];
int n , check[MAX_N];
int ancestor[MAX_N];
int root;
unordered_map<int , int> dist[MAX_N];
int a[MAX_N];
unordered_map<int , int> cl[MAX_N];

void DFS(int u , int father) {
    f[u] = 1;
    for (auto v : adj[u]) {
        if (v != father && !check[v]) {
            DFS(v , u);
            f[u] += f[v];
        }
    }
}

int find_centroid(int u , int father , int root) {
    for (auto v : adj[u]) {
        if (!check[v] && v != father && 2*f[v] >= f[root]) {
            return find_centroid(v , u , root);
        }
    }
    return u;
}

void DFS2(int u , int father , int root , int d) {
    dist[root][u] = d;
    for (auto v : adj[u]) {
        if (v != father && !check[v]) {
            DFS2(v , u , root , d + 1);
        }
    }
}

void centroid(int u , int father) {
    DFS(u , u);
    u = find_centroid(u , u , u); 
    DFS2(u , u , u , 0);
    check[u] = 1;
    if (father != -1) {
        g[u].push_back(father);
        g[father].push_back(u);
    }
    else {
        root = u;
    }
    for (auto v : adj[u]) {
        if (v != father && !check[v]) {
            centroid(v , u);
        }
    }
}

void DFS1(int u , int father) {
    ancestor[u] = father;
    for (auto v : g[u]) {
        if (v != father) {
            DFS1(v , u);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1 ; i < n ; i++) {
        int u , v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int c; cin >> c;
    for (int i = 1 ; i <= n ;i ++) {
        cin >> a[i];
    }
    centroid(1 , -1);
    DFS1(root , -1);
    for (int i = 1 ; i <= n ; i++) {
        int color = a[i];
        int u = i;
        int cr = i;
        while (u != -1) {
            if (cl[u][color] == 0) {
                cl[u][color] = inf;
            }
            cl[u][color] = min(cl[u][color] , dist[u][cr] + 1);
            u = ancestor[u];
        }
    }
    int q; cin >> q;
    for (int i = 1 ; i <= q ; i++) {
        int u , cr; cin >> u >> cr; 
        int r = u;
        int ans = inf;
        while (u != -1) {
            if (cl[u][cr] == 0) {
                cl[u][cr] = inf;
            }
            ans = min(ans , cl[u][cr] + dist[u][r]);
            u = ancestor[u];
        }
        if (ans == inf) cout << -1 << '\n';
        else cout << ans - 1<< '\n';
    }
    return 0;
}