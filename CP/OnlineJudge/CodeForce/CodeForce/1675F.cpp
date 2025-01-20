#include <bits/stdc++.h>

#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long
const int inf = 1e18 + 7;
const int MAX_N = 2e5 + 7;
const int MOD = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test; cin >> test;
    while (test--) {
        int n , k ; cin >> n >> k;
        vector<int> adj[n + 1];
        int s , t; cin >> s >> t;
        vector<int> r(n + 1 , false) , b(n + 1 , false);
        for (int i = 1 ; i <= k ; i++) {
            int x; cin >> x;
            r[x] = true;
        }
        b[t] = true;
        for (int i = 1 ; i < n ; i++) {
            int u , v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        function<void(int , int)> DFS = [&] (int u , int father) {
            for (auto v : adj[u]) {
                if (v != father) {
                    DFS(v , u);
                    if (r[v]) {
                        r[u] = 1;
                    }
                    if (b[v]) {
                        b[u] = 1;
                    }
                }
            }
            return;
        };
        DFS(s , -1);
        int ans = 0;
        for (int i = 1 ; i <= n ;i ++) {
            if (b[i]) {
                ans ++;
            }
            else if (r[i]) {
                ans += 2;
            }
        }
        cout << ans - 1 << '\n';
    }
    return 0;
}