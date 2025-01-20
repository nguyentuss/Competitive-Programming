//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define le(x) (x << 1ll)
#define ri(x) ((x << 1ll) + 1)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
const int inf = 1e9;
const int mod = 1e9 + 7;

void solve() {
    int n , m; cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0 ; i < m ; i++) {
        int u , v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
    }
    vector<vector<int>> f(n , vector<int>(1 << 20)); 
    f[0][1] = 1; 
    for (int mask = 0 ; mask < (1 << 20) ; mask++) {
        for (int i = 0 ; i < n ; i++) {
            if (!f[i][mask]) continue; 
            for (int j : adj[i]) {
                if (!(mask & (1 << j))) {
                    (f[j][mask | (1 << j)] += f[i][mask])%=mod;
                }
            }
        }
    }
    cout << f[n - 1][(1 << n) - 1];
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test; 
    test = 1;
    //cin >> test;
    while (test--) {
        solve();
    }

}