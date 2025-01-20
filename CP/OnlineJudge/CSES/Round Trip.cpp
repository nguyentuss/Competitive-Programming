#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e5 + 7;
const int inf = 1e18;

int a[N];
vector<int> adj[N];
int P[N];
int st , ed;
bool vis[N];

void DFS(int u , int father) {
    vis[u] = 1; 
    for (int v : adj[u]) {
        if (v == father) continue;;
        if (!vis[v]) {
            P[v] = u;
            //cerr << u << " " << v << '\n';
            DFS(v , u);
            if (st) return; 
        }
        else if (vis[v] == 1 && !st && !ed) {
            st = v;
            ed = u; 
            cerr << st << " " << ed << '\n';
            return;
        }
    }
    vis[u] = 2;
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    for (int i = 1 ; i <= m ; i++) {
        int u , v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1 ; i <= n ; i ++) {
        if (!vis[i]) DFS(i , -1);
    }
    //cerr << st << " " << ed << '\n';
    if (!st) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    vector<int> res;
    res.push_back(ed); 
    int u = ed;
    while (u != st) {
        //cerr << u << " ";
        res.push_back(P[u]);
        u = P[u];
    }
    reverse(res.begin() , res.end());
    res.push_back(st);
    cout << res.size() << '\n';
    for (auto x : res) cout << x << " ";
    return 0;
}