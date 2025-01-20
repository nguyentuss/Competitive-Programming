//source:: 
#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long
typedef unsigned __int128 ull;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int inf = 1e18 + 7;
const int N = 3e5 + 7;
const int MOD = 1e9 + 7;

char c[N];
vector<int> adj[N];
int vis[N];
int leaf[N];
int status[N];
int f[N];

void DFS(int u) {
    vis[u] = true; 
    for (auto v : adj[u]) {
        if (!vis[v]) {
            char x;
            if (status[v] == 1) x = 'L';
            if (status[v] == 2) x = 'R';
            if (c[u] != x) {
                f[v] = f[u] + 1;
            }
            else f[v] = f[u];
            DFS(v);
        }
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test; 
    cin >> test;
    while (test--) {
        int n; cin >> n;
        for (int i = 1 ; i <= n ; i++) {
            cin >> c[i];
            vis[i] = false;
            adj[i].clear();
            leaf[i] = 0;
            f[i] = 0;
            status[i] = 0;
        }
        for (int i = 1 ; i <= n ; i++) {
            int l , r; cin >> l >> r;
            if (!l && !r) {
                leaf[i] = true;
                continue;
            }
            // 1:left , 2:right;
            if (l != 0) {
                status[l] = 1;
                adj[i].push_back(l);
                adj[l].push_back(i);
            }
            if (r != 0) {
                status[r] = 2;
                adj[i].push_back(r);
                adj[r].push_back(i);
            }
        }
        DFS(1);
        int ans = inf;
        for (int i = 1 ; i <= n ;i ++) {
            if (leaf[i]) ans = min(ans , f[i]);
        }
        cout << ans << '\n';
    }
    return 0;
}