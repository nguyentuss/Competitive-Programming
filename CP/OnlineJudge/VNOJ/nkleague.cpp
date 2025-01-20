#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 1e3 + 7;
const int MOD = 1e9 + 7;

int a[N][N];
int vis[N];
int f[N];
vector<int> topo;
vector<int> adj[N];

// Điều kiện để thằng trc luôn thắng thằng liền sau thì đường đi dài nhất phải = n
// nhan xet do a[i][j] + a[j][i] = 1 
// => do thi DAG
// TOPO SORT

void DFS(int u) {
    vis[u] = 1; 
    for (auto v : adj[u]) {
        if (vis[v] == 1) {
        }
        if (!vis[v]) {
            DFS(v);
        }
    }
    topo.push_back(u); 
    vis[u] = 2;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for (int i = 1 ; i <= n ;i ++) {
        for (int j = 1 ; j <= n ; j++) {
            char x; cin >> x;
            // cout << x << " ";
            if (x == '1') {
                adj[i].push_back(j);
                //cerr << i << " " << j << '\n';
            }
        }
        //cout << '\n';
    }
    for (int i = 1 ; i <= n ;i ++) {
        if (!vis[i]) DFS(i);
    }
    reverse(topo.begin() , topo.end());
    if (topo.size()) {
        for (auto x : topo) {
            cout << x << " ";
        }
    }
    else {
        cout << -1;
    }
    return 0;
}