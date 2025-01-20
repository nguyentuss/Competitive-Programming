#include <bits/stdc++.h>

#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;

#define ii pair<int , long long>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define ll long long
const ll inf = 1e18 + 7;
const int MAX_N = 5e5 + 7 ;
const int MOD = 1e9 + 7;

struct seg {
    vector<ii> adj;
    vector<ll> IT;
    int ls(int x) {
        return (x << 1);
    }
    int rs(int x) {
        return (ls(x) + 1);
    }
    void init(int len) {
        IT.assign(4*len + 1, inf);
        return;
    }
    void build(int id , int l , int r){
        if (l == r) {
            IT[id] = adj[l].se;
            return;
        }
        int mid = (l + r)>>1;
        build(ls(id) , l , mid);
        build(rs(id) , mid + 1 , r);
        IT[id] = min(IT[ls(id)] , IT[rs(id)]);
    }
    ll get(int id , int l , int r , int L , int R) {
        if (l > R || r < L) return inf;
        if (l <= L && R <= r) {
            return IT[id];
        }
        int mid = (L + R)>>1;
        return min(get(ls(id) , l , r , L , mid) , get(rs(id) , l , r , mid + 1 , R));
    }
    int le(int x) {
        int l = 0 , r = adj.size() - 1;
        int tm = 0;
        if (!adj.size() || x > adj[r].fi) return -1;
        while (l <= r) {
            int mid = (l + r)>>1;
            if (adj[mid].fi >= x) {
                r = mid - 1;
                tm = mid;
            }
            else l = mid + 1;
        }
        return tm;
    }
    int ri(int x) {
        int l = 0 , r = adj.size() - 1; 
        int tm = 0; 
        if (!adj.size() || x < adj[l].fi) return -1;
        while (l <= r) {
            int mid = (l + r)>>1;
            if (adj[mid].fi <= x) {
                l = mid + 1; 
                tm = mid;
            }
            else r = mid - 1;
        }
        return tm;
    }
};

int root;
int n , qq;
int f[MAX_N];
int trace[MAX_N];
int check[MAX_N];
vector<int> g[MAX_N];
vector<ii> adj[MAX_N];
seg leaf[MAX_N];
vector<int> nleaf;
map<ll , ll> dist[MAX_N]; 

int find_centroid(int u , int father , int root) {
    for (auto edge : adj[u]) { 
        int v = edge.first;
        if (v != father && !check[v] && 2*f[v] >= f[root]) {
            return find_centroid(v , u , root);
        }
    }
    return u;
}

void DFS(int u , int father) {
    f[u] = 1;
    for (auto edge : adj[u]) {
        int v = edge.first;
        if (v != father && !check[v]) {
            DFS(v , u);
            f[u] += f[v];
        }
    }
}

void eulertour(int u , int father , int c , ll d) {
    dist[c][u] = d;
    for (auto edge : adj[u]) {
        int v = edge.first;
        ll w = edge.second;
        if (v != father && !check[v]) {
            eulertour(v , u , c , d + w);
        }
    }
}

void centroid(int u , int father) {
    DFS(u , u);
    u = find_centroid(u , u , u);
    eulertour(u , u , u , 0);
    check[u] = 1;
    if (father == -1) {
        root = u;
    }
    else {
        g[u].push_back(father);
        g[father].push_back(u);
    }
    for (auto edge : adj[u]) {
        int v = edge.first;
        if (v != father && !check[v]) {
            centroid(v , u);
        }   
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> qq;
    for (int i = 2 ; i <= n ;i ++) {
        int u , w; cin >> u >> w;
        adj[u].push_back(ii(i , w));
        adj[i].push_back(ii(u , w));
    }
    for (int i = 1 ; i <= n ;i ++) {
        if (adj[i].size() == 1) {
            nleaf.push_back(i);
        }
    }
    centroid(1 , -1);
    queue<int> q;
    q.push(root);
    trace[root] = -1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : g[u]) {
            if (!trace[v]) {
                trace[v] = u;
                q.push(v);
            }
        }
    }
    sort(nleaf.begin() , nleaf.end());
    for (auto u : nleaf) {
        int tm = u;
        while (tm != -1) {
            //cerr << dist[tm][u] << '\n';
            leaf[tm].adj.push_back(ii(u , dist[tm][u]));
            tm = trace[tm];
        }
    }
    q.push(root);
    for (int i = 1 ; i <= n ;i ++) {
        sort(leaf[i].adj.begin() , leaf[i].adj.end());
    }
    for (int u = 1 ; u <= n ; u++) {
        int len = leaf[u].adj.size();
        if (len == 0) continue;
        //cerr << u << " " << len << " " << k << '\n';
        leaf[u].init(len);
        leaf[u].build(1 , 0 , len - 1);
    }
    //cout << leaf[4].get(1 , 0 , 0 , 0 , 1);
    for (int t = 1 ; t <= qq ; t++) {
        int u , l , r; cin >> u >> l >> r;
        int tr = u;
        ll ans = inf;
        int le , ri;
        while (tr != -1) {
            le = leaf[tr].le(l);
            ri = leaf[tr].ri(r);
            ll x = inf;
            if (le != -1 && ri != -1 && le <= ri) {
                //cerr << le << " " << ri << '\n';
                x = leaf[tr].get(1 , le , ri , 0 , leaf[tr].adj.size() - 1);
                //cout << tr << " " << x + dist[tr][u] << '\n';
                ans = min(ans , x + dist[tr][u]);
            }
            //cout << x << '\n';
            tr = trace[tr];
        }
        cout << ans << '\n';
    }
    return 0;
}