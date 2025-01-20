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
const int MAX_N = 1e5 + 7 ;
const int MOD = 1e9 + 7;

map<int , int> dist[MAX_N];
vector<int> adj[MAX_N];
vector<int> g[MAX_N];
int check[MAX_N];
int f[MAX_N];
int trace[MAX_N];
int root;
int n , m;


int find_centroid(int u , int father , int root) {
    for (auto v : adj[u]) {
        if (v != father && !check[v] && 2*f[v] >= f[root]) {
            return find_centroid(v , u , root);
        }
    }
    return u;
}

void DFS(int u , int father) {
    f[u] = 1;
    for (auto v : adj[u]) {
        if (v != father && !check[v]) {
            DFS(v , u);
            f[u] += f[v];
        }
    }
    return;
}


void DFS1(int u , int father , int c , int d) {
    dist[u][c] = d;
    //cerr <<  u << " " << c << " " << dist[u][c] << '\n';
    for (auto v : adj[u]) {
        if (v != father && !check[v]) {
            DFS1(v , u , c , d + 1);
        }
    }
}


void centroid(int u , int father) {
    DFS(u , u);
    u = find_centroid(u , u , u); 
    DFS1(u , u , u , 0);
    check[u] = 1;
    if (father != -1) {
        g[father].push_back(u);
        g[u].push_back(father);
    }
    else root = u;
    for (auto v : adj[u]) {
        if (!check[v]) centroid(v ,u);
    }
    return;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1 ; i < n ; i ++) {
        int u , v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    centroid(1 , -1);
    queue<int> q;
    q.push(root);
    trace[root] = -1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : g[u]) {
            if (!trace[v]) {
                trace[v] = u;
                q.push(v);
            }
        }
    }
    vector<int> ans(MAX_N , inf);
    vector<ii> ask;
    ask.push_back(ii(1 , 1));
    for (int i = 1 ; i <= m ; i++) {
        int t , u; cin >> t >> u;
        ask.push_back(ii(t , u));
    }
    for (auto e : ask) {
        int t = e.fi , u = e.se;
        
        if (t == 1) {
            int v = u;
            while (v != -1) {
                ans[v] = min(ans[v] , dist[u][v]);
                v = trace[v];
                //cout << ans[v] << '\n';
            }
        }
        else {
            int v = u;
            int mm = inf;
            while (v != -1) {
                mm = min(mm , ans[v] + dist[u][v]);
                v = trace[v];
            }
            cout << mm << '\n';
        }
        // for (int i = 1 ; i <= n ; i++) {
        //     cout << ans[i] << " ";
        // }
        // cout << '\n';
    }
    return 0;
}