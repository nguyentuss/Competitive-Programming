#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 +7)
#define int long long
#pragma GCC optimize("Ofast")

set<int> adj[MAX_N];
vector<int> select[MAX_N];
int n , m;
int ans = 0;
set<int> s;

void DFS(int u) {
    vector<int> cur;
    for (auto v : s) {
        if (adj[u].find(v) == adj[u].end()) cur.push_back(v);
    }
    for (auto v : cur) {
        s.erase(v);
    }
    for (auto v : cur) DFS(v);
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1 ; i <= m ; i++) {
        int u , v; cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    for (int i = 1 ; i <= n ; i++) s.insert(i);
    int cnt = 0;
    while (!s.empty()) {
        cnt++; int u = *s.begin();
        s.erase(u);
        DFS(u);
    }
    cout << cnt - 1;
    return 0;
}