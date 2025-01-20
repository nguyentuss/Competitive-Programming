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

int vis[N];
vector<int> adj[N];
int ans[N];
int c[N];

void solve() {
    int n, m; cin >> n >> m;
    // if (m > n - 1) {
    //     cout << "NO\n";
    //     return;
    // }
    map<pii , int> mp;
    for (int i = 0; i < m ; i++) {
        int u , v; cin >> u >> v;
        u--; v--; 
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
        mp[{u , v}] = i + 1;
    }
    queue<int> q; 
    vis[0] = true;
    q.push(0);
    c[0] = 0; 
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!vis[v]) {
                q.push(v) , vis[v] = true; 
                c[v] = c[u] ^ 1; 
                //cerr << u << " " << v << " " <<  mp[{u , v}] << '\n';
                if (c[v]) {
                    int x = mp[{u , v}];
                    if (x > 0) ans[x] = 0; 
                    else ans[mp[{v , u}]] = 1;
                }
                else {
                    int x = mp[{u , v}]; 
                    if (x > 0) ans[x] = 1; 
                    else ans[mp[{v , u}]] = 0;
                }
            }
            else {
                if (c[u] == c[v]) {
                    cout << "NO"; 
                    return;
                }
                else {
                    if (c[u]) {
                        int x = mp[{u , v}]; 
                        if (x > 0) ans[x] = 0; 
                        else ans[mp[{v , u}]] = 1;
                    }
                    else {
                        int x = mp[{u , v}]; 
                        if (x > 0) ans[x] = 1; 
                        else ans[mp[{v , u}]] = 0;                    
                    }
                }
            }
        }
    }
    cout << "YES\n";
    for (int i = 1 ; i <= m ; i++) {
        cout << ans[i];
    }

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