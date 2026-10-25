#include <bits/stdc++.h>
 
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
 
#define ii pair<int , int>
#define f first
#define s second
#define int long long
const int inf = 1e18 + 7;
const int MAX_N = 1e3 + 7;
const int MOD = 1e9 + 7;

vector<int> adj[MAX_N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen("chohang.inp","r",stdin); 
    freopen("chohang.out","w",stdout);
    int n , m; cin >> n >> m;
    int s = 1 , t = n + m + 2;
    vector<vector<int>> resi , aug;
    resi.assign(n + m + 5 , vector<int> (n + m + 5 , 0));
    aug.assign(n + m + 5 , vector<int> (n + m + 5 , 0));
    for (int i = 1 ; i <= n ; i++) {
        int x; cin >> x;
        adj[1].push_back(i + 1);
        adj[i + 1].push_back(1);
        resi[1][i + 1] += x;
    }
    for (int i = 1 ; i <= m ; i++) {
        int x; cin >> x;
        adj[i + 1 + n].push_back(t);
        adj[t].push_back(i + 1 + n);
        resi[i + 1 + n][t] += x;
    }
    int u , v , w; 
    while (cin >> u >> v >> w) {
        resi[u + 1][v + 1 + n] += w;
        adj[u + 1].push_back(v + 1 + n);
        adj[v + 1 + n].push_back(u + 1);
    }
    vector<int> level(m + n + 5 , 0);
    function <void()> BFS = [&] () {
        queue<int> q;
        q.push(s);
        level.assign(n + m + 3 , 0);
        level[s] = 1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto v : adj[u]) {
                if (!level[v] && (resi[u][v] || aug[u][v])) {
                    level[v] = level[u] + 1;
                    q.push(v); 
                }
            }
        }
        return;
    };
    function <int(int , int)> DFS = [&](int u , int mini) {
        if (u == t) return mini;
        int res = 0;
        for (auto v : adj[u]) {
            if (level[v] == level[u] + 1) {
                if (aug[u][v]) {
                    res = DFS(v , min(mini , aug[u][v]));
                    if (res != 0) {
                        aug[u][v] -= res;
                        resi[v][u] += res;
                        return res;
                    }
                }
                else if (resi[u][v]) {
                    res = DFS(v , min(mini , resi[u][v]));
                    if (res != 0) {
                        aug[v][u] += res;
                        resi[u][v] -= res;
                        return res;
                    }
                }
            }
        }
        return res;
    };
    int flow = 0;
    while (true) {
        BFS();
        if (level[t] == 0) break;
        while (int x = DFS(s , inf)) {
            flow += x;
        }
    }
    cout << flow;   
    return 0;
}