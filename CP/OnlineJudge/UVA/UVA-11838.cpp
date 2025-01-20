#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int> > a;
int low[2005], num[2005], numSCC, cnt, connect[2005];
vector<int> S;

void dfs(int u) {
    low[u] = num[u] = cnt++;
    connect[u] = 1;
    S.push_back(u);
    for(int v : a[u]) {
        if (num[v] == -1) dfs(v);
        if (connect[v]) low[u] = min(low[u], low[v]);
    }
    
    if (num[u] == low[u]) {
        numSCC++;
        while(1) {
            int v = S.back(); S.pop_back();
            connect[v] = 0;
            if (u == v) break;
        }
    }
}

int main() {
    
    while(cin >> n >> m, n || m) {
        // reset
        a.clear(); a.resize(2005);
        memset(low, 0, sizeof low);
        memset(num, -1, sizeof num);
        numSCC = 0; cnt = 0;
        memset(connect, 0, sizeof connect);
        S.clear();
        
        for(int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            a[u].push_back(v);
            if (w == 2) a[v].push_back(u);
        }
        
        for(int u = 1; u <= n; u++)
            if (num[u] == -1) dfs(u);
        
        if (numSCC == 1) cout << "1\n";
        else cout << "0\n";
    }
    
    return 0;
}
