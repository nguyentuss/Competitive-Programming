#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ii pair<int , int>
#define sz(x) (int)x.size()

const int N = 1e5 + 7;
const int inf = 1e18;

int n , m;
vector<int> adj[N]; 

vector<int> toposort() {
    vector<int> in_deg(n);
    for (int i = 0 ; i < n ; i++) {
        for (int v : adj[i]) {
            in_deg[v]++;
        }
    }
    queue<int> q;
    vector<int> ret;
    for (int i = 0 ; i < n ; i++) if (!in_deg[i]) q.push(i);
    while (!q.empty()) {
        int u = q.front(); 
        q.pop();
        ret.push_back(u);
        for (int v : adj[u]) {
            if (!--in_deg[v]) {
                q.push(v);
            }
        }                                                       
    }
    return ret;
}

void solve() {
    cin >> n >> m;
    for (int i = 0 ; i < m ; i++) {
        int u , v; cin >> u >> v; 
        u--;  v--;
        adj[u].push_back(v);
    }
    vector<int> res = toposort();
    if (res.size() != n) cout << "IMPOSSIBLE";
    else for (auto x : res) cout << x + 1 << " ";
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}