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

int SC[N] , low[N] , num[N];
vector<int> adj[N];
vector<ii> edge;
int pa[N];
int bridge[3];
int TPLT = 0; 
int vis[N];
int timeDFS = 0;
int n , m;
int sz[N];

void DFS(int u , int father) {
    num[u] = low[u] = ++timeDFS;
    SC[u] = TPLT; pa[u] = father; 
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v == father) continue;
        if (!num[v]) {
            DFS(v , u);
            sz[u] += sz[v];
            low[u] = min(low[u] , low[v]);
        }
        else low[u] = min(low[u] , num[v]);
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    // freopen("test.inp","r",stdin);
    // freopen("test.out","w",stdout);
    cin >> n >> m;
    for (int i = 1 ; i <= m ; i++) {
        int u , v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1 ; i <= n ;i ++) sort(adj[i].begin() , adj[i].end());
    for (int i = 1 ; i <= n ; i++) {
        if (!num[i]) {
            TPLT++;
            //cerr << i << " ";
            DFS(i , i);
        }
    }
    //cerr << TPLT; 
    if (TPLT > 2) {
        cout << 0;
        return 0;
    }
    int ans = 0;
    if (TPLT == 1) {
        //cerr << "HE";
        int total = 0;
        int cnt_bridge = 0;
        for (int u = 1 ; u <= n ; u++) {
            for (int v : adj[u]) {
                if (low[v] == num[v] && pa[v] == u) {
                    //cerr << u << " ";
                    cnt_bridge++;
                    //cerr << u << " " << v << " " << adj[u].size() << '\n';
                    ans = ans + (n - sz[v])*sz[v] - 1;
                }
            }
        }
        cout << ans + (n*(n - 1)/2 - m)*(m - cnt_bridge);
    }
    else if (TPLT == 2) {
        int edge_a = 0 , edge_b = 0;
        for (int u = 1 ; u <= n ; u++) {
            for (int v : adj[u]) {
                edge_a = edge_a + (SC[u] == 1 ? 1 : 0);
                edge_b = edge_b + (SC[u] == 2 ? 1 : 0);
                if (low[v] == num[v] && pa[v] == u) {
                    bridge[SC[u]]++;
                }
            }
        }
        edge_a /= 2; edge_b /= 2;
        int sz_a = 0 , sz_b = 0;
        for (int i = 1 ; i <= n ; i++) {
            if (SC[i] == 1) {
                sz_a++;
            }
            else sz_b++;
        }
        ans = ans + sz_b*sz_a*(edge_a - bridge[1]) + sz_a*sz_b*(edge_b - bridge[2]);
        cout << ans;
    }
    return 0;
}
