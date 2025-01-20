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
    vector<int> a(n + 1);
    vector<vi> adj(n + 1);
    for (int i = 1 ; i <= n ;i ++) {
        cin >> a[i];
    }
    for (int i = 2 ; i <= n ; i++) {
        int x; cin >> x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }
    vector<int> f(n + 1);
    auto DFS = [&](int u , int father , int val , auto &&DFS) -> void {
        f[u] -= val;
        //cerr << f[u] << '\n';
        if (f[u] < 0) {
            val += (-f[u]); 
        }
        val = min(val , n*inf);
        for (int v : adj[u]) {
            if (v != father) {
                DFS(v , u , val , DFS);
            }
        }
    };
    auto check = [&](int x) -> bool {
        f[1] = x;
        for (int i = 2 ; i <= n ;i ++) {
            f[i] = a[i];
        }
        DFS(1 , -1 , x - a[1] , DFS);
        for (int i = 2 ; i <= n ;i ++) {
            if (adj[i].size() == 1 && f[i] < 0) return false;
        }
        return true;
    }; 
    int l = 0 , r = 1e18 + 7; 
    int ans = -1;
    while (l <= r) {
        int mid = (l + r)/2; 
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
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