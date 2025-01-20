#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ii pair<int , int>

const int N = 3e3 + 7;
const int inf = 1e18;

/*BELLMAN FORD(O(|V|.|E|))*/
vector<ii> adj[N];

int BellmanFord(int n , int m) {
    queue<int> q; vector<int> d(n , inf);
    vector<int> cnt(n , 0);
    vector<bool> vis(n , 0);
    d[0] = 0; q.push(0); vis[0] = true;
    //cerr << "DEBUG";
    while (!q.empty()) {
        int u = q.front(); 
        if (cnt[u] <= n) vis[u] = false;
        q.pop();
        //cerr << u << '\n';
        for (auto [v,uv] : adj[u]) {
            if ((d[u] + uv) < d[v]) {
                d[v] = d[u] + uv;
                if (!vis[v]) {
                    vis[v] = true; 
                    q.push(v);
                    cnt[v] ++;
                    if (cnt[v] > n) {
                        d[v] = -1e15;
                    }
                }
            }
        }
    }
    return (-d[n - 1] >= 1e15 ? -1 : -d[n - 1]);
}

void solve() {  
    int n , m; cin >> n >> m;
    for (int i = 0 ; i < m ; i++) {
        int u , v , c; cin >> u >> v >> c;
        u--; v--;
        adj[u].push_back(ii(v , -c));
        //adj[v].push_back(ii(u , -c));
    }
    cout << BellmanFord(n , m);
}


main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t = 1;
    while (t--) {
        solve();
    }
   

    return 0;
}