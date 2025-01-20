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

const int inf = 1e18 + 7;
const int N = 2e5 + 7;

int n , m;
vector<int> adj[N];
int num[N] , low[N] , tail[N] , sz[N];
int timeDFS = 0;
int ver[N];
int bridge = 0;
int ans = inf;

void DFS(int u , int father) {
    num[u] = low[u] = ++timeDFS;
    sz[u] = 1;
    int child = 0;
    for (int v : adj[u]) {
        if (v == father) continue;
        child++;
        if (!num[v]) {
            DFS(v , u); 
            sz[u] += sz[v];
            low[u] = min(low[u] , low[v]);
            if (low[v] == num[v]) {
                ans = min(ans , n * (n - 1)/2 - sz[v] * (n - sz[v]));
            }
        }
        else {
            low[u] = min(low[u] , num[v]);
        }
    }
}

void init() {
    timeDFS = 0;
    for (int i = 0 ; i < n ; i++) {
        sz[i] = low[i] = num[i] = 0; 
        adj[i].clear(); 
    }
    ans = inf;
}

void solve() {
    cin >> n >> m; 
    init();
    for (int i = 0 ; i < m ; i++) {
        int u , v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v); 
        adj[v].push_back(u);
    }
    ans = n * (n - 1)/2;
    DFS(1 , -1);
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