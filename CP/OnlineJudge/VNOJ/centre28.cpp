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
const int inf = 1e9 + 7;
const int MAX_N = 3e4 + 7;
const int MOD1 = 1e9 + 7;
const int MOD2 = 1e9 + 9;

vector<ii> adj[MAX_N];
int d1[MAX_N];
int d2[MAX_N];
ii c1[MAX_N];
ii c2[MAX_N];
int n , m;
int dist[MAX_N];
ii c[MAX_N];

ii add(int a , int b , int c , int d) {
    return ii((a + b)%MOD1 , (c + d)%MOD2);
}

ii mul(int a , int b , int c, int d) {
    return ii((a*b)%MOD1 , (c * d)%MOD2);
}

void calc(int s , int type) {
    priority_queue<ii , vector<ii> , greater<ii>> pq;   
    for (int i = 1 ; i <= n ; i++) {
        dist[i] = inf;
        c[i] = ii(0 , 0);
    }
    pq.push(ii(0 , s));
    dist[s] = 0;
    c[s] = ii(1 , 1);
    while(!pq.empty()) {
        int u = pq.top().se;
        int du = pq.top().fi;
        pq.pop();
        for (auto edge : adj[u]) {
            int v = edge.se;
            int d = edge.fi; 
            if (dist[v] > (du + d)) {
                dist[v] = du + d; 
                c[v] = c[u];
                pq.push(ii(dist[v] , v));
            }
            else if (dist[v] == (du + d)) {
                c[v] = add(c[v].fi , c[u].fi , c[v].se , c[u].se);
            }
        }
    }
    if (type == 0) {
        for (int i = 1 ; i <= n ; i++) {
            d1[i] = dist[i];
            c1[i] = c[i];
        }
    }
    else {
        for (int i = 1 ; i <= n ; i++) {
            d2[i] = dist[i];
            c2[i] = c[i];
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1 ; i <= m ; i++) {
        int u , v , w; cin >> u >> v >> w;
        adj[u].push_back(ii(w , v));
        adj[v].push_back(ii(w , u));
    }
    calc(1 , 0);
    calc(n , 1);
    vector<int> ad;
    for (int i = 2 ; i < n ;i ++) {
        //cerr << arr.c1[i] << " " << arr.c2[i] << " " << arr.c1[arr.n] << '\n';
        ii x = mul(c1[i].fi , c2[i].fi , c1[i].se , c2[i].se);
        if ((d1[i] + d2[i]) == d1[n] && (((x.fi == c1[n].fi) && (x.se == c1[n].se))) ) continue;;
        // if(d1[i] + d2[i] > d1[n] || (((x.fi != c1[n].fi) || (x.se != c1[n].se)))) {
        //     ad.push_back(i);
        // }  
        ad.push_back(i);
    } 
    cout << ad.size() << '\n';
    for (auto aa : ad) {
        cout << aa << '\n';
    }
    return 0;
}