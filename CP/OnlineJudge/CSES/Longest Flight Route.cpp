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
    priority_queue<int , vector<int> , greater<int>> q;
    vector<int> ret;
    for (int i = 0 ; i < n ; i++) if (!in_deg[i]) q.push(i);
    while (!q.empty()) {
        int u = q.top(); 
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
    vector<int> topo = toposort();
    vector<int> f(n , 1);
    vector<int> P(n , -1);
    vector<bool> in_g(n , 0);
    bool status = false;
    queue<int> q; q.push(0);
    in_g[0] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : adj[u]) {
            if (!in_g[v]) {
                in_g[v] = true;
                q.push(v);
            }
        }
    }
    for (int u : topo) {
        if (!in_g[u]) continue;
        for (int v : adj[u]) {
            if (f[v] < f[u] + 1) {
                f[v] = f[u] + 1;
                P[v] = u;
            }
        }
    }
    int pos = n - 1;
    vector<int> trace;
    while (pos != -1) {
        trace.push_back(pos);
        pos = P[pos];
    }
    reverse(trace.begin() , trace.end()); 
    //for (int x : trace) cerr << x + 1 << " ";
    if (f[n - 1] == 1) {
        cout << "IMPOSSIBLE";
    } 
    else {
        cout << sz(trace) << '\n';
        for (int x : trace) cout << x + 1 << " ";
    }
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}