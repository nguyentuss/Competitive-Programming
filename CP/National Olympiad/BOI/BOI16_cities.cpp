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
const int MAX_N = 1e5 + 7;
const int MOD = 1e9 + 7;

int n , m , k; 
vector<ii> adj[MAX_N];
int f[MAX_N][(1 << 5) + 1];
int a[MAX_N];
vector<int> mm[50];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k >> m;
    for (int i = 1 ; i <= n ;i ++) {
        for (int j = 1 ; j < (1 << k) ; j++) {
            f[i][j] = inf;
        }
    }
    priority_queue<iii , vector<iii> , greater<iii>> pq;
    for (int i = 0 ; i < k ; i++) {
        cin >> a[i];
        f[a[i]][1 << i] = 0;
        pq.push(iii(0 , ii(a[i] , 1 << i)));
    }
    for (int i = 1 ; i <= m ; i++) {
        int u , v , w; cin >> u >> v >> w;
        adj[u].push_back(ii(v , w));
        adj[v].push_back(ii(u , w));
    }
    for (int mask1 = 0 ; mask1 < (1 << k) ; mask1++) {
        for (int mask2 = 0 ; mask2 < (1 << k) ; mask2 ++) {
            if (!(mask1 & mask2)) {
                mm[mask1].push_back(mask2);
            }
        }
    }
    while (!pq.empty()) {
        int u = pq.top().se.fi;
        int mask1 = pq.top().se.se;
        int du = pq.top().fi;
        pq.pop();
        if (du != f[u][mask1]) continue;;
        for (auto edge : adj[u]) {
            int v , w; 
            tie(v , w) = edge;
            for (auto mask2 : mm[mask1]) {
                if (!(mask1 & mask2) && (f[u][mask1] + f[v][mask2] + w) < f[v][mask1|mask2]) {
                    f[v][mask1|mask2] = f[u][mask1] + f[v][mask2] + w;
                    pq.push(iii(f[v][mask1|mask2] , ii(v , mask1|mask2)));
                }
            }
        }
    }
    int ans = inf;
    for (int i = 1 ; i <= n ; i++) {
        ans = min(ans , f[i][(1 << k) - 1]);
    }   
    cout << ans;
    return 0;
}