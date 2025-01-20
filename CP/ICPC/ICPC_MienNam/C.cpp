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
    vector<int> w(n + 1); 
    vector<int> a(n + 1);
    vector<int> b(n + 1); 
    for (int i = 1 ; i <= n ; i++) {
        cin >> w[i];
    }
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
    }
    for (int i = 1 ; i <= n ; i++) {
        cin >> b[i];
    }
    vector<vector<int>> adj(n + 1);
    for (int i = 1 ; i <= n ; i++) {
        adj[b[i]].push_back(a[i]);
    }
    vector<int> vis(n + 1);
    int sum = 0;
    int sz = 0;
    int tmp = 0;
    vector<int> cl;
    function<void(int)> DFS = [&](int u) {
        vis[u] = true;
        cl.push_back(w[u]);
        tmp += w[u];
        sz ++;
        for (auto v : adj[u]) {
            if (!vis[v]) {
                DFS(v);
            }
        }
    };

    int mn = w[1];
    for (int i = 1 ; i <= n ; i++) {
        mn = min(mn, w[i]);
    }
    //cout << sum;
    for (int i = 1 ; i <= n ; i++) {
        if (!vis[i]) {
            DFS(i);
            sort(all(cl));
            if (sz > 1) {
                sum += tmp;
            }
            if (sz > 2) {
                // cout << mn << " " << sum << " " << cl[0] * (sz - 2) << " " << (cl[0] + mn) + mn * (sz) << "\n";
                sum += min(cl[0] * (sz - 2), (cl[0] + mn) + mn * (sz));
                // sum += cl[0] * (sz - 2);
            }
            cl.clear();
            sz = 0;
            tmp = 0;
        }
    }

    cout << sum;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test; 
    test = 1;
    // cin >> test;
    while (test--) {
        solve();
    }

}