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

const int inf = 1e9;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 3); 
    vector<vector<int>> adj(n + 3); 
    for (int i = 0 ; i < n ; i++) cin >> a[i]; 
    for (int i = 1 ; i < n ; i++) {
        int u; cin >> u;
        u--; 
        adj[u].push_back(i); 
    }
    vector<vector<int>> f(n + 1 , vector<int>(n + 1 , 0));
    vector<int> d(n , inf);
    auto DFS = [&] (int u , auto &&DFS) -> int {
        if (adj[u].size() == 0) {
            f[u][0] = inf;
            d[u] = 1;
            return 0;
        }
        int ans = 0;
        int sum = 0;
        for (int v : adj[u]) {
            ans += DFS(v , DFS);
            sum += a[v];
            d[u] = min(d[u] , d[v] + 1); 
            for (int i = 1 ; i <= n ; i++) f[u][i] += f[v][i - 1];
        }
        if (a[u] <= sum) {
            f[u][0] = sum - a[u];
        }
        else {
            int last = a[u] - sum;
            f[u][0] = 0;
            for (int i = 1 ; i <= n ; i++) {
                if (last - f[u][i] >= 0) {
                    ans = ans + i*f[u][i];
                    last = last - f[u][i];
                    f[u][i] = 0;
                }
                else {
                    ans = ans + i*last;
                    f[u][i] = f[u][i] - last;
                    last = 0;
                }
            }
            //ans = ans + d[u] * last;
        }
        return ans;
    };
    cout << DFS(0 , DFS) << '\n';
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