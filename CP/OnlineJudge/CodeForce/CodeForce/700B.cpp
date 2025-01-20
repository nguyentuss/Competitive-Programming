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
#define int long long
const int inf = 1e18 + 7;
const int MAX_N = 2e5 + 7;
const int MOD = 1e9 + 7;

int mark[MAX_N];
int f[MAX_N];
vector<int> adj[MAX_N];

void DFS(int u , int father) {
    if (mark[u]) f[u] = 1;
    for (auto v : adj[u]) {
        if (v != father) {
            DFS(v , u);
            f[u] += f[v];
        }
    } 
    return;
}

int centroid(int u , int father , int root) {
    for (auto v : adj[u]) {
        if (v != father && 2*f[v] >= f[root]) {
            return centroid(v , u , root);
        }
    }
    return u;
}

void calc(int u , int father) {
    f[u] += 
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    k *= 2;
    for (int i = 1 ; i <= k ; i++) {
        int u; cin >> u;
        mark[u] = 1;
    }
    for (int i = 1 ; i < n ; i++) {
        int u , v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1 , -1);
    int c = centroid(1 , -1 , 1);
    calc(c , -1);
    return 0;
}