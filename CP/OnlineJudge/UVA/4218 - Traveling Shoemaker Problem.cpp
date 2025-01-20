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
    int n , C;
    while (cin >> n >> C && n && C) {
        vector<vi> g(n);
        for (int i = 0 ; i < C ; i++) {
            int k; cin >> k;
            for (int j = 0 ; j < k ; j++) {
                int x; cin >> x;
                g[x].push_back(i);
            }
        }
        vector<vector<pair<int , int>>> adj(C);
        vector<int> deg(C);
        vector<bool> vp(n);
        for (int i = 0 ; i < n ; i++) {
            int u = g[i][0] , v;
            if (sz(g[i]) == 1) {
                v = u;
            }
            else {
                v = g[i][1];
            }
            //assert(u < C && v < C);
            deg[u]++;   deg[v]++;
            adj[u].emplace_back(v , i);
            adj[v].emplace_back(u , i);
        }
        vector<int> tin(C , -1) , low(C , -1) , visited(C , false);
        int timer = 0;
        auto DFS = [&](int v , int p , auto &&DFS) -> void{
            visited[v] = true;
            tin[v] = low[v] = timer++;
            bool parent_skipped = false;
            for (auto [to , idx] : adj[v]) {
                if (to == p && !parent_skipped) {
                    parent_skipped = true;
                    continue;
                }
                if (visited[to]) {
                    low[v] = min(low[v], tin[to]);
                } else {
                    DFS(to, v , DFS);
                    low[v] = min(low[v], low[to]);
                    if (low[to] > tin[v])
                        vp[idx] = 1;
                        
                }
            }
        };
        int ncomp = 0;
        for (int i = 0 ; i < C ; i++) {
            if (deg[i] != 0 && !visited[i]) {
                DFS(0 , -1 , DFS);
                ncomp++;
            }
        }
        int odd = 0;
        vector<int> v_odd;
        for (int i = 0 ; i < C ; i++) {
            if (deg[i] & 1) {
                odd++;
                v_odd.push_back(i);
            }
        }
        //cerr << odd << '\n';
        if (ncomp > 1 || odd > 2) cout << -1 << '\n';
        else if (!odd) {
            cout << 0 << '\n';
        } 
        else {
            int ans = n;
            for (int x : v_odd) {
                if (sz(adj[x]) == 1) {
                    ans = min(ans , adj[x][0].second);
                }
                else {
                    for (auto [u , idx] : adj[x]) {
                        if (!vp[idx]) {
                            ans = min(ans , idx);
                        }
                    }
                }
            }
            cout << ans << '\n';
        }
    }
    
    return; 
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