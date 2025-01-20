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
const int mod = 1e9 + 7;

void solve() {
    int n, t; cin >> n >> t;
    vector<int> a(n);
    for (int i = 0 ; i < n ; i++) cin >> a[i];
    vector<vi> adj(n);
    vector<vi> g(n); 
    for (int i = 1 ; i < n ; i++) {
        int u , v; cin >> u >> v;
        u--; v--; 
        if (a[u] <= t && a[v] <= t) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if (a[u] < t && a[v] < t) {
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }
    vector<int> sz1(n) , sz2(n) , f1(n), f2(n); 
    vector<int> dp1(n) , dp2(n);
    function<void(int , int)> down1 = [&](int u , int father) {
        sz1[u] = 1;
        for (int v : adj[u]) {
            if (v != father) {
                down1(v , u);
                sz1[u] += sz1[v];
                (f1[u] += f1[v] + sz1[v])%=mod;
            }
        }
    };
    function<void(int , int)> down2 = [&](int u , int father) {
        sz2[u] = 1;
        for (int v : g[u]) {
            if (v != father) {
                down2(v , u); 
                sz2[u] += sz2[v]; 
                (f2[u] += f2[v] + sz2[v])%=mod;
            }
        }
    };
    function<void(int , int , int)> up1 = [&](int u , int father , int size_tree) {
        dp1[u] = (f1[u]*max(0ll, size_tree - 2))%mod;
        for (int v : adj[u]) {
            if (v != father) {
                f1[v] = ((f1[u] - sz1[v] + mod)%mod + (size_tree - sz1[v])%mod)%mod;
                up1(v , u , size_tree);
            }
        }
    };
    function<void(int , int , int)> up2 = [&](int u , int father, int size_tree) {
        dp2[u] = (f2[u]*max(0ll , size_tree - 2))%mod;
        for (int v : g[u]) {
            if (v != father) {
                f2[v] = ((f2[u] - sz2[v] + mod)%mod + (size_tree - sz2[v])%mod)%mod;
                up2(v , u , size_tree);
            }
        }
    };
    function<int(int , int)> pow = [&](int a , int n) {
        if (n == 1) return a;
        int child = pow(a , n/2)%mod;
        if (n % 2 == 1) return ((child*child)%mod*a%mod)%mod;
        else return ((child*child)%mod);
    };
    vector<int> v1 , v2;
    for (int i = 0 ; i < n ; i++) {
        if (!sz1[i]) down1(i , -1) , v1.push_back(i);
        if (!sz2[i]) down2(i , -1) , v2.push_back(i);
    }
    for (int u : v1) {
        up1(u , -1 , sz1[u]); 
    }
    for (int u : v2) {
        up2(u , -1 , sz2[u]);
    }
    int ans1 = 0 , ans2 = 0;
    for(int i = 0 ; i < n ;i ++) {
        (ans1 += dp1[i])%=mod; 
        (ans2 += dp2[i])%=mod;
    }
    cout << dp2[0];
    //cout << (ans1 - ans2 + mod)%mod;
    cout << ((ans1 - ans2 + mod)%mod*pow(2 , mod - 2)%mod)%mod;
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