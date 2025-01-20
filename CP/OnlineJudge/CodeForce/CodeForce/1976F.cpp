//source:: 
#include <bits/stdc++.h>

using namespace std;

#define int long long

const int inf = 1e18 + 7;
const int N = 3e5 + 7;
const int MOD = 1e18 + 7;

using namespace std;

int n, d[N], trace[N];
vector <int> adj[N];
vector <int> val[N];
bool vis[N];
int controlled = 0, ans[N];

int DFS(int u, int p) {
    d[u] = 1;
    for(int &v : adj[u]) {
        if (v != p) {
            int x = DFS(v , u) + 1;
            if (d[u] < x) {
                d[u] = x; 
                trace[u] = v;
            }
        }
    }
    return d[u];
}

void Spread(int u) {
    while(u) vis[u] = 1, u = trace[u], controlled++;
}


void solve(){
    cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        adj[i].clear(); 
        d[i] = 0; 
        vis[i] = 0;
        val[i].clear();
        trace[i] = 0;
    }
    controlled = 0;
    for (int i = 1 ; i < n ; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1 , -1);
    for (int i = 1 ; i <= n ; i++) val[d[i]].push_back(i);
    ans[1] = 1;
    int k = 1;
    for (int i = n ; i >= 1 ; i--)  {
        for(auto &u : val[i]) {
            if(!vis[u]) {
                ++k;
                Spread(u);
                ans[k] = n - controlled;
            }
        }
    }

    for (int i = k + 1 ; i <= n ; i++) 
        ans[i] = n - controlled;
    int cur = 1;
    for (int i = 2; i <= n; i += 2) {
        cout << ans[i] << ' ';
        cur++;
    }
    for (int i = cur ; i < n ; i++) cout << 0 << " ";
    cout << '\n';
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); 
    cout.tie(NULL);
    int test = 1;
    cin >> test;
    while(test--) {
        solve();
    }
    return 0;
}
