#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ii pair<int , int>
#define sz(x) (int)x.size()

const int N = 2e5 + 7;
const int inf = 1e18;

int vis[N];
vector<int> adj[N];
int d[N];
bool cycle[N];
int sz[N];
int P[N];
int n;

void find_cycle(int u) {
    vis[u] = 1;
    for (int v : adj[u]) {
        if (!vis[v]) {
            find_cycle(v);
        }
        else if (vis[v] == 1) {
            stack<int> s;
            cycle[v] = true;
            s.push(v);
            int tr = P[v];
            while (tr != u) {
                s.push(tr);
                //cerr << tr << '\n'; 
                cycle[tr] = true;
                tr = P[tr];
            }
            if (u != v)
                s.push(u);
            int sz_cycle = s.size();
            while (!s.empty()) {
                int u = s.top();
                s.pop();   
                sz[u] = sz_cycle;
            }
        }
    }
    vis[u] = 2;
}

void DFS(int u) {
    vis[u] = 1;
    for (int v : adj[u]) {
        if (!vis[v]) DFS(v);
        if (!sz[u] && sz[v]) {
            sz[u] = sz[v] + 1;
        }
    }
}

void solve() {
    cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        int x; cin >> x;
        adj[i].push_back(x);
        P[i] = x;
        //cerr << i << " " << x << '\n';
    }
    for (int i = 1 ; i <= n ; i++) {
        if (!vis[i]) {
            find_cycle(i);
        }
    }
    for (int i = 1 ; i <= n ; i++) {
        vis[i] = false;
        if (cycle[i]) vis[i] = true;
    }
    for (int i = 1 ; i <= n ; i++) {
        if (!vis[i]) DFS(i);
    }
    for (int i = 1 ; i <= n ; i++) 
        cout << sz[i] << " ";
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}