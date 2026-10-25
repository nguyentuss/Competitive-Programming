#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)
#define inf (int) (1e9 + 7)
#define ii pair<int , int>
#define f first
#define s second

struct edge {
    int u , v , w;
};

map<int , bool> pos;
map<int , int> col;
vector<ii> adj[MAX_N];
vector<edge> sav;
int a[MAX_N];
int ans = inf;
vector<int> d(MAX_N , inf);

void dijsktra(int root) {
    priority_queue<ii , vector<ii> , greater<ii>> pq;
    pq.push(ii(0 , root));
    pos[root] = false;
    d[root] = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        if (pos[u] && u != root) {
            ans = min(ans , d[u]);
            return;
        }
        pq.pop();
        for (auto x : adj[u]) {
            int v = x.first , w = x.second;
            if (d[v] > (d[u] + w)) {
                d[v] = d[u] + w;
                pq.push(ii(d[v] , v));
            }
        }
    }
}

int main() {    
    ios::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
   // freopen("mintime.inp","r",stdin);
   // freopen("mintime.out","w",stdout);
    int n , k , l; cin >> n >> k >> l;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
    }
    for (int i = 1 ; i <= l ; i++) {
        int u , v ,  w; cin >> u >> v >> w;
        pos[u] = true; pos[v] = true;
        sav.push_back({u , v , w});
    }
    int num = 0;
    for (auto x : pos) { 
        col[x.first] = ++num;
    }
    pos.clear();
    for (int i = 1 ; i <= n ;i ++) {
        pos[col[a[i]]] = true;
    }
    if (pos.size() == 1) {
        cout << 0;
        return 0;
    }
    for (auto x : sav) {
        int u = col[x.u] , v = col[x.v];
        adj[u].push_back(ii(v , x.w));
        adj[v].push_back(ii(u , x.w));
    }
    for (int i = 1 ; i <= n ; i++) {
        dijsktra(col[a[i]]);
    }
    cout << ans*3;
    return 0;
}