#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MAX_N (int) (1e5 + 7)


vector<int> adj[MAX_N];
vector<int> num(MAX_N , 0);
vector<int> low(MAX_N , 0);
vector<int> tail(MAX_N , 0);
vector<bool> found(MAX_N , 0);
int timeDFS = 0;
int ans = 0;
int bridge = 0;

void DFS(int u , int father) {
    num[u] = low[u] = ++timeDFS;
    int child = 0;
    for (auto v : adj[u]) {
        if (v == father) continue;
        if (!num[v]) {
            child++;
            DFS(v , u);
            low[u] = min(low[u] , low[v]);
            if (low[v] >= num[v]) {
                bridge++;
                //cerr << "DEBUG";
            }
            //cerr << low[u] << " " << num[u] << " " << low[v] <<" " << num[v] << '\n';
            if (u == father) {
                if (child >= 2) found[u] = true;
            }
            else if (low[v] >= num[u]) found[u] = true;
        }
        else low[u] = min(low[u] , num[v]);
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n , m; cin >> n >> m;
    for (int i = 1 ; i <= m ; i++) {
        int u , v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1 ; i <= n ; i++) {
        if (!num[i]) DFS(i , i);
    }
    for (int i = 1 ; i <= n ; i++) {
        ans += found[i];
    }
    cout << ans << " " << bridge;
    return 0;
}
