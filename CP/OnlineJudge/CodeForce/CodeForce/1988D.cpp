//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
const int inf = 1e18;

void solve() {
    int n; cin >> n;
    vector<int> a(n); 
    for (int i = 0 ; i < n ; i++) cin >> a[i];
    vector<vector<int>> adj(n);
    for (int i = 1 ; i < n ; i++) {
        int u , v; cin >> u >> v;
        u--; v--; 
        adj[u].push_back(v); 
        adj[v].push_back(u);
    }
    vector<vi> f(n , vi(22 , 0));
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < 22 ; j++) {
            f[i][j] = a[i] * j;
        }
    }
    auto dfs = [&](int u , int father , auto &&dfs) -> void {
        for (int v : adj[u]) {
            if (v != father) {
                dfs(v , u , dfs);
                for (int j = 1 ; j < 22 ; j++) {
                    int x = inf ;
                    for (int k = 1 ; k < 22; k++) {
                        if (k == j) continue;
                        x = min(x , f[v][k]);
                    }
                    f[u][j] += x;
                }
            }
        }
    };
    dfs(0 , -1 , dfs); 
    int ans = inf; 
    for (int j = 1 ; j < 22 ; j++) {
        ans = min(ans , f[0][j]); 
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test; 
    test = 1;
    cin >> test;
    while (test--) {
        solve();
    }

}