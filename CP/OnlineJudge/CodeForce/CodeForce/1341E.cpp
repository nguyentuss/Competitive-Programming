//source:: 
#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define vi vector<int>
#define fi first
#define se second
#define int long long
#define sz(a) (int) a.size()
typedef unsigned __int128 ull;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int inf = 1e18 + 7;
const int N = 1e6 + 7;
const int MOD = 1e9 + 7;

void solve() {
    int n , m; cin >> n >> m;
    vector<int> island(m + 1);
    for (int i = 1 ; i <= m ; i++) {
        cin >> island[i];
    }
    sort(island.begin() + 1 , island.begin() + 1 + m);
    int g , r; cin >> g >> r;
    vector<vi> d(m + 1 , vi(g + 1 , 0));
    vector<vi> vis(m + 1 , vi(g + 1, 0));
    deque<pair<int,int>> dq;
    dq.push_back({0 , 0});
    int ans = inf;
    while (!dq.empty()) {
        auto [u , time_g] = dq.front(); 
        int nu = island[u];
        dq.pop_front();
        if (u == m - 1) {
            //cerr << u << " " << time_g << '\n';
            if (time_g + island[m] - island[u] <= g) {
                ans = min(ans , d[u][time_g] + island[m] - island[u] + time_g);
            }
        }
        if (u > 0) {
            int nv = island[u - 1];
            if (time_g + nu - nv <= g) {
                if (time_g + nu - nv < g) {
                    if (!vis[u - 1][time_g + nu - nv]) {
                        vis[u - 1][time_g + nu - nv] = 1;
                        d[u - 1][time_g + nu - nv] = d[u][time_g];
                        dq.push_front({u - 1 , time_g + nu - nv});
                    }
                }
                else {
                    if (!vis[u - 1][0]) {
                        vis[u - 1][0] = 1; 
                        d[u - 1][0] = d[u][time_g] + g + r;
                        dq.push_back({u - 1 , 0});
                    }
                }
            }    
        }
        if (u < m - 1) {
            int nv = island[u + 1];
            if (time_g + nv - nu <= g) {
                if (time_g + nv - nu < g) {
                    if (!vis[u + 1][time_g + nv - nu]) {
                        vis[u + 1][time_g + nv - nu] = 1;
                        d[u + 1][time_g + nv - nu] = d[u][time_g];
                        dq.push_front({u + 1 , time_g + nv - nu});
                    }
                }
                else {
                    if (!vis[u + 1][0]) {
                        vis[u + 1][0] = 1; 
                        d[u + 1][0] = d[u][time_g] + g + r;
                        dq.push_back({u + 1 , 0});
                    }
                }
            }
        }
    }
    cout << (ans == inf ? -1 : ans) << '\n';
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test = 1; 
    //cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}