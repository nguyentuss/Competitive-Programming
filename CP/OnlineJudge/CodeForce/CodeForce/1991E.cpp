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
    int n , m; cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0 ; i < m ;i ++) {
        int u , v; cin >> u >> v;
        u--; v--;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    vector<int> vis(n);
    vector<int> a(n);
    auto DFS = [&](int u , auto &&DFS) -> bool {
        vis[u] = true; 
        for (int v : adj[u]) {
            if (!vis[v]) {
                a[v] = a[u] ^ 1;
                if (!DFS(v , DFS)) return false;
            }
            else {
                if (a[u] == a[v]) return false;
            }
        }
        return true;
    };

    if (!DFS(0 , DFS)) {
        cout << "Alice" << endl;
        for (int i = 1 ; i <= n ; i++) {
            cout << "1 2" << endl;
            int a , b; cin >> a >> b;
        }
    }
    else {
        cout << "Bob" << endl;
        vector<vector<int>> c(2); 
        for (int i = 0 ; i < n ; i++) c[a[i]].push_back(i + 1);
        for (int i = 1 ; i <= n ; i++){
            int u , v; cin >> u >> v;
            u--; v--;
            if (u > v) swap(u , v);
            if (v != 2) {
                if (c[u].size()) {
                    cout << c[u].back() << " " << u + 1 << endl;
                    c[u].pop_back();
                }
                else {
                    cout << c[v].back() << " " << v + 1 << endl;
                    c[v].pop_back();
                }
            }
            else {
                if (c[u].size()) {
                    cout << c[u].back() << " " << u + 1 << endl;
                    c[u].pop_back();
                }
                else {
                    int x = u ^ 1; 
                    cout << c[x].back() << " " << v + 1 << endl; 
                    c[x].pop_back();
                }
            }
        }

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