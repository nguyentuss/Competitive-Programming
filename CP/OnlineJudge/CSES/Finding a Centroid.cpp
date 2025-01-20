#include <bits/stdc++.h>
 
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
 
#define ii pair<int , int>
#define f first
#define s second
#define int long long
const int inf = 1e9 + 7;
const int MAX_N = 2e5 + 7;
const int MOD = 1e9 + 7;

vector<int> adj[MAX_N];
vector<int> g[MAX_N];
int check[MAX_N] , f[MAX_N];
int root;

void DFS(int u , int father) {
    f[u] = 1;
    for (auto v : adj[u]) {
        if (v != father && !check[v]) {
            DFS(v , u);
            f[u] += f[v];
        }
    }
}

int find_ct(int u , int father , int root) {
    for (auto v : adj[u]) {
        if (!check[v] && v != father && f[v]*2 >= f[root]) {
            return find_ct(v , u , root);
        }
    }
    return u;
}

void centroid(int u , int father) {
    DFS(u , u);
    u = find_ct(u , u , u); check[u] = 1;
    if (father != -1) {
        g[u].push_back(father);
        g[father].push_back(u);
    }
    else root = u;
    for (auto v : adj[u]) {
        if (!check[v] && v != father) {
            centroid(v , u);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for (int i = 1 ; i < n ;i ++) {
        int u , v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    centroid(1 , -1);
    cout << root;
    return 0;
}