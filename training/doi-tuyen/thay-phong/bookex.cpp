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
const int inf = 1e9 + 7;
const int MAX_N = 1e6 + 7;
const int MOD = 1e9 + 7;

int vis[MAX_N];
vector<int> adj[MAX_N];
int root[MAX_N];
int sz[MAX_N];
int a[MAX_N];

void init() {
    for (int i = 1 ; i < MAX_N ; i++) {
        root[i] = i;
        sz[i] = 1;
    }
}

int find_root(int u) {
    return (root[u] == u) ? u : root[u] = find_root(root[u]);
}

int ans[MAX_N];

void merge(int u , int v) {
    u = find_root(u);
    v = find_root(v);
    if (u != v) {
        if (sz[u] < sz[v]) swap(u , v);
        root[v] = u;
        sz[u] += sz[v];   
    }
    else {
        ans[u] = 1;
    }
}


signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    init();
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        merge(i , a[i]);
    }
    for (int i = 1 ; i <= n ; i++) {
        cout << sz[find_root(i)] << " ";
    }

    return 0;
}