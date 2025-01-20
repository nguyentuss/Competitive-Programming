#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (21)

int n , m, k;
vector<int> adj[MAX_N];
int c[1000][1000];

void calc() {
    for (int i = 1 ; i <= k ; i++) {
        
    }
}

void backtr(int i) {
    for (int j = 0 ; j <= 1 ; j++) {
        X[i] = j;
        if (i == k) calc();
        else backtr(i + 1);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 1 ; i <= m ;i ++) {
        int u , v , w; cin >> u >> v >> w;
        adj[u].push_back(ii(v);
        adj[v].push_back(ii(u);
        c[u][v] = c[v][u] = inf;
    }
    for (int i = 1 ; i <= k ; i++) {
        int v , w; cin >> v >> w;
        adj[1].push_back(v);
        adj[v].push_back(1);
        c[1][v] = c[v][1] = min(c[1][v] , w);
    }
    backtr(1);

    return 0;
}