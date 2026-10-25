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
const int inf = 1e9 + 7;
const int MAX_N = 1e5 + 7 ;
const int MOD = 1e9 + 7;

vector<int> adj[MAX_N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n , m , x; cin >> n >> m >> x;
    for (int i = 1 ; i <= m ; i++) {
        int u , v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<ii> pq;
    vector<ii> d(n + 1 , ii(inf , 0));
    for (int i = 1 ; i <= x ; i++) {
        int u; cin >> u;
        d[u].fi = 0;
        d[u].se = u;
        pq.push(ii(u , u));
    }
    int ans = inf;
    while (!pq.empty()) {
        int u = pq.front().se;
        pq.pop();
        for (int v : adj[u]) {
            if (d[u].se != d[v].se && d[u].fi != inf && d[v].fi != inf) {
                ans = min(ans , d[u].fi + d[v].fi + 1);
            }
            if (d[v].fi > (d[u].fi + 1)) {
                d[v].fi = d[u].fi + 1;
                d[v].se = d[u].se;
                pq.push(ii(d[v].fi , v));
            }
        }
    }
    cout << ans;
    return 0;
}