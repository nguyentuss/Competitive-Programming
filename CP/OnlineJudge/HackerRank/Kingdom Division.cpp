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
const int N = 2e5 + 7;
const int mod = 1e9 + 7;

int f[N][2];
int g[N][2];
vector<vi> adj(N);

void DFS(int u , int father) {
    for (int v : adj[u]) {
        if (v != father) {
            DFS(v , u);
        }
    }
    f[u][0] = f[u][1] = 1; 
    for (int v : adj[u]) {
        if (v != father) {
            (f[u][0] *= g[v][1])%=mod; 
            (f[u][1] *= g[v][0])%=mod;
        }
    }
    g[u][0] = g[u][1] = 1;
    for (int v : adj[u]) {
        if (v != father) {
            (g[u][0] *= (f[v][0] + g[v][1] + g[v][0])%mod)%=mod;
            (g[u][1] *= (f[v][0] + g[v][1] + g[v][1])%mod)%=mod;
        }
    }
    g[u][0] = (g[u][0] - f[u][0] + mod)%mod; 
    g[u][1] = (g[u][1] - f[u][1] + mod)%mod;
}

void solve() {
    int n; cin >> n;
    for (int i = 1 ; i < n ; i++) {
        int u , v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(0 , -1);
    cout << (g[0][1] + g[0][0])%mod;
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