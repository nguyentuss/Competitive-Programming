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
    int n , k; cin >> n >> k;
    vector<int> a(n);
    vector<vector<int>> adj(n); 
    for (int &u : a) cin >> u;
    for (int i = 1 ; i < n ; i++){
        int u , v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v); 
        adj[v].push_back(u);
    }
    vector<int> f0(n) , f1(n);
    function<void(int , int)> DFS = [&](int u , int father) {
        f0[u] = a[u];
        f1[u] = a[u] ^ k;
        int sum0 = 0;
        int sum1 = 0; 
        for (int v : adj[u]) {
            if (v != father) {
                DFS(v , u);
                sum0 += f0[v]; 
                sum1 += f1[v];
            }
        }
        //cerr << u << " " << sum0 << " " << sum1 << " " << f0[1] <<  " " << f1[1] << '\n';
        for (int v : adj[u]) {
            if (v != father) {
                f0[u] = max(f0[u] , max(sum0 + a[u] , f1[v] + (sum0 - f0[v]) + (a[u] ^ k)));
                f1[u] = max(f1[u] , max(f1[v] + a[u] , f0[v] + (a[u] ^ k)));
            }
        }
    };
    DFS(0 , -1);
    //for (int i = 0 ; i < n ; i++) cout << f0[i] << " " << f1[i] << '\n';
    cout << f0[0];
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