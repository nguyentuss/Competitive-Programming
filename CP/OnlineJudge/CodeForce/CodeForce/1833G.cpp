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

void solve() {
    int n; cin >> n;
    vector<vector<pii>> adj(n);
    for (int i = 1 ; i < n ; i++) {
        int u ,v ; cin >> u >> v; 
        u--; v--; 
        adj[u].push_back(pii(i , v));
        adj[v].push_back(pii(i , u));
    }
    if (n % 3 != 0) {
        cout << -1 << '\n';
        return;
    }
    vector<int> sub(n , 1);
    vector<int> ans;
    vector<int> cut(n);
    function<bool(int , int)> DFS = [&](int u , int father) {
        for (auto [id , v] : adj[u]) {
            if (v != father) {
                if (!DFS(v , u)) return 0 ;
                if (sub[v] == 3) {
                    ans.push_back(id);
                }
                if (sub[v] < 3) sub[u] += sub[v];
                if (sub[u] > 3) return 0;
            }
        }
        return 1;
    };  
    if (!DFS(0 , -1) || (n % 3 != 0))   {
        cout << -1 << '\n';
        return;
    }
    else {
        cout << sz(ans) << '\n';
        for (int x : ans) cout << x << " ";
        cout << '\n';
        return;
    }
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
