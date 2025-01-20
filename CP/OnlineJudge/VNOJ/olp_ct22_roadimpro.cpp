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
typedef pair<int , pii> piii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
const int inf = 1e9;
const int base = 3e11 + 3;

void solve() {
    int n , m , q; cin >> n >> m >> q;
    vector<vector<pii>> adj(n);
    for (int i = 0 ; i < m ; i++) {
        int u , v , w; cin >> u >> v >> w;
        u--; v--; 
        adj[u].push_back(pii(w ,v));
    }

    vector<vector<vi>> d(n , vector<vi>(2008 , vi(2 , inf)));
    for (int i = 1 ; i <= 2000 ; i++) {
        min_heap<piii> pq;
        pq.push(piii(0 , pii(0 , 0)));
        d[0][i][0] = 0;
        while (!pq.empty()) {
            auto [du , tmp] = pq.top();
            auto [u , status] = tmp;
            pq.pop();
            if (d[u][i][status] != du) continue;
            for (auto [uv , v] : adj[u]) {
                if (!status) {
                    if (d[u][i][0] + uv < d[v][i][0]) {
                        d[v][i][0] = d[u][i][0] + uv;
                        pq.push(piii(d[v][i][0] , pii(v , 0)));
                    }
                    if (d[u][i][0] + i < d[v][i][1]) {
                        d[v][i][1] = d[u][i][0] + i; 
                        pq.push(piii(d[v][i][1] , pii(v , 1)));
                    }
                }
                else {
                    if (d[u][i][1] + uv < d[v][i][1]) {
                        d[v][i][1] = d[u][i][1] + uv; 
                        pq.push(piii(d[v][i][1] , pii(v , 1)));
                    }
                }
            }
        }
    }
    while (q--) {
        int s , t; cin >> s >> t;
        s--;
        //cout << s << " " << t << '\n';
        cout << min(d[s][t][0] , d[s][t][1]) << '\n';
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