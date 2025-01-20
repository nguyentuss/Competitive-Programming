#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 3e3 + 7;
const int MOD = 1e9 + 7;

vector<int> adj[N];

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n , m; cin >> n >> m;
    for (int i = 1 ; i <= m ;i ++) {
        int u , v; cin >> u >> v;
        adj[u].push_back(v); 
        adj[v].push_back(u);
    }
    int ans = inf;
    for (int i = 1 ; i <= n ;i ++) {
        queue<int> q;
        q.push(i);
        vector<int> d(n + 1);
        vector<int> parent(n + 1); 
        vector<int> vis(n + 1);
        parent[i] = -1;
        vis[i] = true;
        while (!q.empty()) {
            int u = q.front();
            q.pop(); 
            for (auto v : adj[u]) {
                if (!vis[v]) {
                    d[v] = d[u] + 1;
                    vis[v] = true;
                    parent[v] = u;
                    q.push(v);
                }
                else if (parent[u] != v) {
                    //cout << i << " " <<  u << " " << v << " " << d[u] << " " << d[v] << '\n';
                    ans = min(ans , d[u] + d[v] + 1);
                }   
            }
        }
        //cout << ans << " ";
    }
    cout << (ans == inf ? -1 : ans);
    return 0;
}