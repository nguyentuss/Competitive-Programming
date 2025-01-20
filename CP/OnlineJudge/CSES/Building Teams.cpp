#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e5 + 7;
const int inf = 1e18;

vector<int> adj[N];
int mark[N];
bool vis[N];

bool check(int n) {
    queue<int> q;
    for (int i = 1 ; i <= n ; i++) {
        if (vis[i]) continue;
        vis[i] = true;
        mark[i] = 0;
        q.push(i);
        while (!q.empty()) {
            int u = q.front(); 
            q.pop();
            for (int v : adj[u]) {
                if (!vis[v]) {
                    //cerr << u << " " << v << '\n';
                    q.push(v);
                    vis[v] = 1;
                    mark[v] = mark[u] ^ 1;
                }
                else if (mark[u] == mark[v]) return false;
            }
        }
    }
    return true;
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n , m; cin >> n >> m;
    for (int i = 1 ; i <= m ; i++) {
        int u , v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (!check(n)) cout << "IMPOSSIBLE";
    else {
        for (int i = 1 ; i <= n ; i++) cout << mark[i] + 1 << " ";
    }
    return 0;
}   