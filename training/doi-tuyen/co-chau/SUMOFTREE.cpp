#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MAX_N (int) (1e5 + 7)
const int inf = 1e9 + 7;

vector<int> adj[MAX_N];
int a[MAX_N] , b[MAX_N] , down[MAX_N] , downxor[MAX_N];
int f[MAX_N] , fxor[MAX_N] , dp[MAX_N];
int n , k , totalxor = 0 , total = 0;

void prepare(int u , int father) {
    down[u] = a[u];
    downxor[u] = b[u];
    for (auto v : adj[u]) {
        if (v == father) continue;
        prepare(v , u);
        downxor[u] += downxor[v];
        down[u] += down[v];
    }
}

void DFS(int u , int father) {
    dp[u] = downxor[u] + total - down[u];
    for (auto v : adj[u]) {
        if (v == father) continue;
        dp[u] = max(dp[u] , totalxor - downxor[v] + down[v]);
        DFS(v , u);
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen("sumoftree.inp","r",stdin);
    freopen("sumoftree.out","w",stdout);
    int t; cin >> t;
    while (t--) {
        cin >> n >> k;
        total = totalxor = 0;
        memset(dp , 0 , sizeof dp);
        memset(downxor , 0 , sizeof downxor);
        memset(down , 0 , sizeof down);
        for (int i = 1 ; i <= n ; i++) {
            adj[i].clear();
            cin >> a[i];
            b[i] = a[i] ^ k;
            total += a[i];
            totalxor += b[i];
        }
        for (int i = 1 ; i < n ; i++) {
            int u , v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        prepare(1 , -1);
        DFS(1 , -1);
        int ans = total;
        for (int i = 1 ; i <= n ;i ++) {
            ans = max(ans , dp[i]);
        }
        cout << ans << "\n";
    }
    return 0;
}
