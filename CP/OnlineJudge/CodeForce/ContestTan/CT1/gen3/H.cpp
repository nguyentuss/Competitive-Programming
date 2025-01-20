#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e9 + 7;

struct seg {
    int u , v , w;
};

bool cmp(seg &a , seg &b) {
    return a.w < b.w;
}

vector<ii> adj[N];
int root[N];
int n , m;
vector<seg> edge;
int numpow[N];
int pp2[N];
int f[N];
int g[N];
int sz[N];
int bicc[N];

int find_root(int u) {
    if (root[u] == u) return u;
    else {
        return root[u] = find_root(root[u]);
    }
}

bool merge(int u , int v) {
    u = find_root(u); 
    v = find_root(v);
    if (u != v) {
        if (sz[u] < sz[v]) swap(u , v);
        root[v] = u;
        sz[u] += sz[v];
        return true;
    }
    else return false;
}

void DFS(int u , int father) {
    g[u] = 1;
    for (auto edge : adj[u]) {
        int v , w; tie(v , w) = edge;
        if (v != father) {
            DFS(v , u);
            f[w] += g[v]*(n - g[v]); 
            g[u] += g[v];
        }
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);    
    cin >> n >> m;
    for (int i = 1 ; i <= n ;i ++) {
        root[i] = i;
        sz[i] = 1;
    }
    for (int i = 1 ; i <= m ;i ++) {
        int u , v , w; cin >> u >> v >> w; 
        edge.push_back({u , v , w});
    }
    sort(edge.begin() , edge.end() , cmp);
    for (auto x : edge) {
        if (merge(x.u , x.v)) {
            adj[x.u].push_back(ii(x.v , x.w)); 
            adj[x.v].push_back(ii(x.u , x.w));
        }
    }
    DFS(1 , -1);
    for (int i = 0 ; i < N ; i++) {
        bicc[i] = f[i]%2;
        f[i + 1] = f[i + 1] + f[i]/2;
    }
    bool start = false;
    for (int i = N ; i >= 0 ; i--) {
        if (!start && bicc[i] == 1) start = true;
        if (start) cout << bicc[i];
    }
    return 0;
}