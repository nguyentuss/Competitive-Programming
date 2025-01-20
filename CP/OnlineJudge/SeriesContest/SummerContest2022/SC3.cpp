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

int root[MAX_N] , dist[MAX_N];
vector<ii> adj[MAX_N];
int n , q;

int find_root(int u) {
    if (u == root[u]) return u;
    else {
        return root[u] = find_root(root[u]);
    }
}

int unionset(int u , int v) {
    u = find_root(u);
    v = find_root(v);
    if (u != v) {
        root[v] = u;
    }
}

bool check(int u , int v) {
    u = find_root(u);
    v = find_root(v);
    return (u == v);
}

int BFS(int x) {
    for (int i = 1 ; i <= n ;i ++) {
        dist[i] = inf;
    }
    dist[x] = 0;
    queue<int> q;
    q.push(x);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto x : adj[u]) {
            int v = x.second;
            int w = x.first;
            if (dist[v] == inf) {
                dist[v] = dist[u] + w;
                q.push(v);
            }       
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen("SC3.inp","r",stdin);
    freopen("SC3.out","w",stdout);
    int t; cin >> t;
    while (t--) {
        cin >> n >> q;
        for (int i = 1 ; i <= n ; i++) {
            root[i] = i;
            adj[i].clear();
        }
        for (int i = 1; i <= q ; i++) {
            char ask; int u , v , w; cin >> ask;
            if (ask == '!') {
                cin >> u >> v >> w;
                if (!check(u , v)) {
                    //cerr << i << '\n';
                    unionset(u , v);
                    adj[u].push_back(ii(w , v));
                    adj[v].push_back(ii(-w , u));
                }
            }
            else {
                cin >> u >> v;
                BFS(u);
                if (dist[v] == inf) cout << "UNKNOWN" << '\n';
                else cout << dist[v] << '\n';
            }
        }
    }
    return 0;
}