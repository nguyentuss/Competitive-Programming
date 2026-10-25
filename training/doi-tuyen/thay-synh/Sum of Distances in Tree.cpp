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
    vector<vector<int>> adj(n);
    for (int i = 1 ; i < n ; i++) {
        int u , v; cin >> u >> v;
        //u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> size(n) , f(n);
    function<void(int , int)> DFS = [&](int u , int father) {
        size[u] = 1;
        for (int v : adj[u]) {
            if (v != father) {
                DFS(v , u);
                size[u] += size[v];
                f[u] = f[u] + f[v] + size[v];
            }
        }
    };

    vector<int> up(n);
    function<void(int , int)> DFS1 = [&](int u , int father) {
        for (int v : adj[u]) {
            if (v != father) {
                up[v] = up[u] - size[v] + (n - size[v]);
                DFS1(v , u);
            } 
        }
    };

    DFS(0 , -1);
    up[0] = f[0];
    DFS1(0, -1);
    for (int i = 0 ; i < n ; i++) cout << up[i] << " ";
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