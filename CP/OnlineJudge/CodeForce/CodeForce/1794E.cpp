//source:: 
#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define repn(i , a , b) for(int i = a; i<= (b); ++i)
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

int MOD , base;

vector<int> pw , down , up;
vector<int> adj[N];
vector<int> a; 
vector<int> c;
int n;
int ans[N];

void DFS1(int u , int father) {
    down[u] = 1;
    for (int v : adj[u]) {
        if (v != father) {
            //cerr << u << " " << v << '\n';
            DFS1(v , u); 
            down[u] = (down[u] + (base*down[v])%MOD)%MOD;
        }
    }
}

void DFS2(int u , int father) {
    int sum = 0;
    for (int v : adj[u]) {
        if (v != father) {
            sum = (sum + down[v])%MOD;
            up[v] = (up[v] + (base*up[u])%MOD)%MOD;
        }
    }
    for (int v : adj[u]) {
        if (v != father) {
            up[v] = (up[v] + base*(base%MOD*(sum - down[v])%MOD))%MOD;
            up[v] = (up[v] + MOD)%MOD;
            DFS2(v , u);
        }
    }
    return;
}

void remod(int m , int b) {
    MOD = m; base = b;
    unordered_map<int , int> mp;
    pw.resize(n); down.resize(n); up.resize(n);
    pw[0] = 1;
    rep(i , 1 , n) pw[i] = (pw[i - 1]*base)%MOD;
    int hashA = 0;
    rep(i , 0 , n) hashA = (hashA + (pw[i]*c[i])%MOD)%MOD; 
    if (!c[0]) mp[(hashA + 1)%MOD]++;
    else {
        rep(i , 1 , n) {
            mp[(hashA + pw[i])%MOD]++;
        }
    }
    DFS1(0 , 0);
    rep(i , 0 , n) up[i] = 1;
    DFS2(0 , 0);
    rep(i , 0 , n) {
        int tm = ((up[i] + down[i])%MOD - 1 + MOD)%MOD;
        if (mp[tm] > 0) {
            ans[i]++;
        }
    }
}

void solve() {
    cin >> n;
    a.resize(n) ; c.resize(n); 
    rep(i , 0 , n - 1) {
        cin >> a[i];
        c[a[i]]++;
    }
    rep(i , 0 , n - 1) {
        int u , v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    remod(998244353 , 200003);
    remod(904322329 , 200009);
    vector<int> res;
    rep(i , 0 , n) {
        if (ans[i] == 2) {
            res.push_back(i + 1);
        }
    }
    //cout << '\n';
    cout << sz(res) << '\n';
    for (int x : res) cout << x << " ";
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