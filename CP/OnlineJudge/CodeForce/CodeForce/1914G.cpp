//source:: 
#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long
typedef unsigned __int128 ull;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 998244353;
const int LOG = 20;

struct DSU{
    vector<int> sz,root,l,r;
    DSU(int n) {
        sz.resize(n + 1);
        root.resize(n + 1);
        l.resize(n + 1 , inf);
        r.resize(n + 1 , -1);
        for (int i = 1 ; i <= n ; i++) {
            root[i] = i;
            sz[i] = 1;
        }
    }
    int find_root(int u) {
        return (u == root[u] ? u : find_root(root[u]));
    }      
    void merge(int u , int v) {
        u = find_root(u);
        v = find_root(v);
        if (u != v) {
            if (sz[u] < sz[v]) swap(u , v);
            root[v] = u;
            sz[u] += sz[v];
            l[u] = min(l[u] , l[v]);
            r[u] = max(r[u] , r[v]);
        }
        return;
    } 
};

struct SegmentTre {
    vector<pair<int , int>> IT;
    SegmentTre(int n) {
        IT.resize(8*n + 1 , ii(inf , -1));
    }
    void update(int id , int l , int r , int i , ii val) {
        if (i < l || r < i) return;
        if (l == r) {
            IT[id] = val;
            return;
        }
        int mid = (l + r) >> 1;
        update(id << 1 , l , mid , i , val);
        update(id << 1 | 1 , mid + 1 , r , i , val); 
        IT[id].first = min(IT[id << 1].first , IT[id << 1 | 1].first);
        IT[id].second = max(IT[id << 1].second , IT[id << 1 | 1].second);
        return;
    }
    ii query(int id , int l , int r , int L , int R) {
        if (r < L || l > R) return ii(inf  , 0);
        if (L <= l && r <= R) return IT[id]; 
        int mid = (l + r) >> 1;
        ii ans;
        ans.first = min(query(id << 1 , l , mid , L , R).first , query(id << 1 | 1 , mid + 1 , r , L , R).first);
        ans.second = max(query(id << 1 , l , mid , L , R).second , query(id << 1 | 1 , mid + 1 , r , L , R).second);
        return ans;
    }
};

struct SparseTable {
    vector<int> pre;
    vector<vector<pair<int, int>>> g;
 
    SparseTable(vector<pair<int, int>> &v) {
        int n = v.size() - 1;
        g.resize(n + 1);
        pre.resize(n + 2);
        for (int i = 1; i <= n; i++)
            g[i].resize(LOG);
 
        pre[1] = 0;
        for (int i = 2; i <= n; i++)
            pre[i] = pre[i >> 1] + 1;
 
        for (int i = 1; i <= n; i++)
            g[i][0] = {v[i].first, v[i].second};
 
        for (int k = 1; k < LOG; k++) {
            for (int i = 1; i + (1 << k) - 1 <= n; i++) {
                g[i][k].first = min(g[i][k - 1].first, g[i + (1 << (k - 1))][k - 1].first);
                g[i][k].second = max(g[i][k - 1].second, g[i + (1 << (k - 1))][k - 1].second);
            }
        }
    }
 
    int queryMin(int l, int r) {
        int d = r - l + 1, k = pre[d];
 
        return min(g[l][k].first, g[r - (1 << k) + 1][k].first);
    }
 
    int queryMax(int l, int r) {
        int d = r - l + 1, k = pre[d];
 
        return max(g[l][k].second, g[r - (1 << k) + 1][k].second);
    }
};
 

int c[2*N];
void solve() {
    int n; cin >> n;
    DSU dsu(n);
    //SegmentTre st(n);
    //vector<int> c(2*n + 1);
    for (int i = 1 ; i <= 2*n ; i++) {
        cin >> c[i];
        dsu.l[c[i]] = min(dsu.l[c[i]] , i);
        dsu.r[c[i]] = max(dsu.r[c[i]] , i);
    }
    vector<pair<int , int>> v(2*n + 1);
    for (int i = 1 ; i <= 2*n  ; i++) {
        v[i] = {dsu.l[c[i]] , dsu.r[c[i]]};
    }
    SparseTable st(v);
    //for (int i = 1 ; i <= 2*n ; i++) {
        //st.update(1 , 1 , 2*n , i , ii(dsu.l[c[i]] , dsu.r[c[i]]));
    //}
    for (int i = 1 ; i <= n ; i++) {
        int l = st.queryMin(dsu.l[i] , dsu.r[i]);
        int r = st.queryMax(dsu.l[i] , dsu.r[i]);
        //auto [l , r] = st.query(1 , 1 , 2*n , dsu.l[i] , dsu.r[i]);
        dsu.merge(c[l] , i); 
        dsu.merge(c[r] , i);
    }
    vector<pair<int , int>> f(n + 1); // find left-most and right-most on one pair of lights
    for (int i = 1 ; i <= n ; i++) {
        int u = dsu.find_root(i);
        f[i].fi = dsu.l[u];
        f[i].se = dsu.r[u];
    }   
    int comp = 0;
    vector<int> vis(n + 1);
    vector<int> cc(n + 1);
    for (int i = 1 ; i <= 2*n ; i++) {
        int cl = c[i];
        if (!vis[cl]) {
            comp++;
            for (int j = f[cl].fi ; j <= f[cl].se ; j++) {
                vis[c[j]] = comp;
                cc[comp]++;
            }
        }
    }

    vector<int> num(n + 1);
    for (int i = 1 ; i <= n ; i++) {
        int len = f[i].se - f[i].fi + 1; 
        if (len == cc[vis[i]]) {
            num[vis[i]] += 2;
        }
    }
    int ans = 1;
    for (int i = 1 ; i <= comp ; i++) {
        (ans *= num[i])%=MOD;
    }   
    cout << comp << " " << ans << '\n';
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test; 
    cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}