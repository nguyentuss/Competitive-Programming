#include <bits/stdc++.h>

#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long
const int inf = 1e18 + 7;
const int MAX_N = 1e2 + 7;
const int MOD = 1e9 + 7;

vector<int> adj[MAX_N];
int vis[MAX_N];
int n , m;

void DFS(int u , vector<int> a) {
    if (u != 2) a[u] = true;
    else {
        for (int i = 1 ; i <= n ;i ++) {
            if (a[i]) {
                cout << i << " ";
            }
        }
        cout << '\n';
    }
    // for (int i = 1 ; i <= n ; i++) {
    //     cout << a[i] << " ";
    // }
    cout << '\n';
    for (auto v : adj[u]) {
        if (!a[v]) {
            DFS(v , a);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1 ; i <= m ;i ++) {
        int u , v; cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> a(n + 1 , 0);
    DFS(1 , a);
    return 0;
}