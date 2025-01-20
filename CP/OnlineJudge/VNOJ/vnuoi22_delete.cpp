#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MAX_N (int) (2e5 + 7)
#define MAX_M (int) (5e5 + 7)
#define inf (int) (1e18 + 7)
#define MOD (int) (998244353)
        #define ii pair<int , int>
        #pragma GCC optimize("Ofast")

struct edge {
    int u , w , type;
};

int n , k , m;
vector<edge> adj[MAX_N];
int d[MAX_N];
vector<ii> dag;
int cnt[MAX_N] , cnttov[MAX_N];
bool vis[MAX_N];
int f[MAX_M];

void calc() {
    for (int i = 1 ; i <= n ;i ++)  {
        for (auto v : adj[i]) {
            if ((d[i] + v.w) == d[v.u]) {
            dag.push_back(ii(v.u , v.type));
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 1 ; i <= m ; i++) {
        int u , v , w; cin >> u >> v >> w;
        adj[u].push_back({v , w , 0});
        adj[v].push_back({u , w , 0});
    }
    for (int i = 1 ; i <= k ; i++) {
        int v , w; cin >> v >> w;
        adj[1].push_back({v , w , 1});
        adj[v].push_back({1 , w , 1});
    }   
    //for (auto x : adj[1]) cerr << x.u << " " << x.w << " " << x.type << '\n';
    priority_queue<ii , vector<ii> , greater<ii>> pq;
    for (int i = 1 ; i <= n ; i++) d[i] = inf;
    d[1] =0;
    pq.push(ii(0 , 1));
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (auto v : adj[u]) {
            if (d[v.u] > (d[u] + v.w)) {
                d[v.u] = d[u] + v.w;
                pq.push(ii(d[v.u] , v.u));
            }
        }
    }
    calc();
    f[0] = 1;
    for (int i = 1 ; i <= k ; i++) {
        (f[i] = f[i - 1]*2LL)%=MOD;
    }
    int num = k;
    //if (num <= 0) cout << "YES";
    for (auto v : dag) {
        // cerr << v.first << " " << v.second << '\n';
        if (v.second == 1) { 
            num--;
            cnt[v.first]++;
        }
        cnttov[v.first]++;
    } 
    int ans = f[num];
    for (int i = 1 ; i < MAX_N ; i++) {
        if (!cnt[i]) continue;
        if (cnttov[i] > cnt[i]) {
            //cout << "2131231" << '\n';
            ans = (ans*f[cnt[i]]%MOD)%MOD;
        }
        else {
            // cerr << i << " " << cnt[i]  << " " << ans << '\n';
            ans = (ans*((f[cnt[i]] - 1 + MOD)%MOD))%MOD;
        }
    }
    cout << ans;    
    return 0;
}