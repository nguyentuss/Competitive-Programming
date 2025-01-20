//source:: https://codeforces.com/contest/1004/problem/E
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
const int N = 2e5 + 7;
const int MOD = 1e9 + 7;
const int LOG = 20;

int d[N];
int P[N];
vector<ii> adj[N];
int vis[N];
int ed[N];

void DFS1(int u , int p) {
    for (auto [v , c] : adj[u]) {
        if (v != p) {
            d[v] = d[u] + c; 
            DFS1(v , u);
        }
    }
}

void DFS2(int u , int p) {
    for (auto [v , c] : adj[u]) {
        if (v != p) {
            d[v] = d[u] + c;
            P[v] = u;
            ed[v] = c;
            DFS2(v , u);
        }
    }
}

void DFS3(int u) {
    vis[u] = 1; 
    for (auto [v , c] : adj[u]) {
        if (!vis[v]) {
            DFS3(v);
            d[u] = max(d[u] , d[v] + c);
        }
    }
}

int find_mx(int n) {
    int mx_i = 1;
    for (int i = 1 ; i <= n ;i ++) if (d[i] > d[mx_i]) mx_i = i;
    for (int i = 1 ; i <= n ;i ++) d[i] = 0;
    return mx_i;
}

struct SparseTable {
    vector<int> pre;
    vector<vector<int>> g;
 
    SparseTable(vector<int> &v) {
        int n = v.size() + 7;
        g.resize(n + 1);
        pre.resize(n + 2);
        for (int i = 1; i <= n; i++)
            g[i].resize(LOG);
 
        pre[1] = 0;
        for (int i = 2; i <= n; i++)
            pre[i] = pre[i >> 1] + 1;
 
        for (int i = 1; i <= n; i++)
            g[i][0] = v[i];
 
        for (int k = 1; k < LOG; k++) {
            for (int i = 1; i + (1 << k) - 1 <= n; i++) {
                g[i][k] = max(g[i][k - 1], g[i + (1 << (k - 1))][k - 1]);
            }
        }
    }
 
    int queryMax(int l, int r) {
        int d = r - l + 1, k = pre[d];
        return max(g[l][k], g[r - (1 << k) + 1][k]);
    }
};

void solve() {
    int n, k; cin >> n >> k;
    int sss = 0;
    for (int i = 1 ; i < n ; i ++) {
        int u , v , c; cin >> u >> v >> c;
        if (!sss) sss = u;
        adj[u].push_back(ii(v , c));
        adj[v].push_back(ii(u , c)); 
    }
    DFS1(1 , -1);
    int mx_i = find_mx(n);
    DFS2(mx_i , -1);
    mx_i = find_mx(n);
    vector<int> tr;
    int tm = mx_i;
    while (tm != 0) {
        tr.push_back(tm); 
        tm = P[tm];
    }
    reverse(tr.begin() , tr.end());
    for (int x : tr) vis[x] = true;
    for (int x : tr) DFS3(x);
    vector<int> a(n + 1);
    for (int i = 1 ; i < sz(tr) ; i++) {
        a[i] = ed[tr[i]];
    }
    vector<int> v;
    v.push_back(0);
    for (int x : tr) v.push_back(d[x]);
    SparseTable st(v); 
    vector<int> f(n + 3 , 0);
    for (int i = 1 ; i < sz(tr) ; i++) {
        f[i + 1] = f[i] + a[i];
    }
    int ans = inf;
    int l = 1 , r = k; 
    while (l <= r) {
        int mn = inf;
        int mid = (l + r)/2; 
        for (int i = 1 ; i <= sz(tr) - mid + 1 ; i++) {
            mn = min(mn , max({f[i] , st.queryMax(i , i + mid - 1) , f[sz(tr)] - f[i + mid - 1]}));
        }
        if (mn == inf) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
            ans = mn;
        } 
    }
    
    cout << ans;
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