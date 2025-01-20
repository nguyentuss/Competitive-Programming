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

struct DSU{
    int n;
    vector<vector<int>> adj;    
    vi color;
    vi cnt;
    vi siz;
    int ans = 0;
    vi f;
    DSU(int n): n(n), adj(n), cnt(n+1), color(n+1), siz(n), f(n) {
        predfs(0 , -1);
    }

    void predfs(int u , int father) {
        siz[u] = 1;
        for (int v : adj[u]) {
            if (v != father) {
                predfs(v , u); 
                siz[u] += siz[v];
            }
        }
    }

    void update(int u , int father , int val) {
        if (val == 1 && !cnt[color[u]]) {
            ans += color[u];
        }
        if (val == -1 && cnt[color[u]] == 1) {
            ans -= color[u];
        }
        cnt[color[u]] += val;
        for (int v : adj[u]) {
            if (v != father) {
                update(v , u , val);    
            }
        }
    }

    void DFS(int u , int father) {
        int bigChild = -1; 
        for (int v : adj[u]) {
            if (v == father) continue; 
            if (bigChild == -1 || siz[v] > siz[bigChild]) bigChild = v;
        }
        for (int v : adj[u]) {
            if (v != father && v != bigChild) {
                DFS(v , u);
                update(v , u , -1);
            }
        }
        if (bigChild != -1) DFS(bigChild , u);
        for (int v : adj[u]) {
            if (v != father && v != bigChild) {
                update(v , u , 1);
            }   
        }
        if (!cnt[color[u]]) ans += color[u]; 
        // cout << ans << '\n';
        cnt[color[u]]++;
        f[u] = ans;
    }

};

void solve() {
    int n; cin >> n;
    vi a(n);
    DSU dsu(n);
    for (int i = 0 ; i < n ; i++) {
        int c; cin >> c;
        dsu.color[i] = c;
    }
    for (int i = 0 ; i < n - 1 ; i++) {
        int u , v; cin >> u >> v; 
        u--; v--; 
        dsu.adj[u].push_back(v);
        dsu.adj[v].push_back(u);
    }
    dsu.DFS(0 , -1);
    for (int i = 0 ; i < n ; i++) {
        cout << dsu.f[i] << ' ';
    }
    cout << '\n';
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
