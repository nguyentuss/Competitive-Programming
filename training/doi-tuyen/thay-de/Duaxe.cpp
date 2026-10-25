#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MAX_N (int) (1e4 + 7)

vector<int> adj[MAX_N];
bool c[MAX_N][MAX_N];
int dist[MAX_N];

void bridge(int u , int father) {
    int numchild = 0;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    //freopen("duaxe.inp","r",stdin);
    //1freopen("duaxe.out","w",stdout);
    int n , m; cin >> n >> m;
    for (int i = 1 ; i <= m ; i++) {
        int u , v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bridge(1 , 1);
    return 0;
}