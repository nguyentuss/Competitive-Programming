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
const int inf = 1e9 + 7;
const int MAX_N = 2e5 + 7;
const int MOD = 1e9 + 7;

int f[MAX_N];
bool check[MAX_N];
int cnt[MAX_N];
int BIT[MAX_N];
vector<int> adj[MAX_N];
int ans = 0;
int n , k1 , k2 , maxh = 0;
int IT[4 * MAX_N];
int lz[4 * MAX_N];

int ls(int id) {
    return (id << 1);
}

int rs(int id) {
    return (ls(id) + 1);
}

void DFS(int u , int father) {
    f[u] = 1;
    for (auto v : adj[u]) {
        if (v != father && !check[v]) {
            DFS(v , u);
            f[u] += f[v];
        }
    }
}

int get(int x) {
    int val = 0;
    x++;
    for ( ; x > 0 ; x -= x & (-x)) {
        val += BIT[x];
    }
    return val;
}

void update(int x , int val) {
    x++;
    for ( ; x <= n ; x += x & (-x)) {
        BIT[x] += val;
    }
}

int find_centroid(int u , int father , int root) {
    for (auto v : adj[u]) {
        if (!check[v] && v != father && 2*f[v] >= f[root]) {
            return find_centroid(v , u , root);
        }
    }
    return u;
}

void calc(int u , int father , bool status , int d) {
    if (d > k2) return;
    maxh = max(maxh , d);
    if (!status) {
        ans = ans + get(k2 - d) - get(k1 - d - 1); 
    }
    else {
        update(d , 1);
    }
    for (auto v : adj[u]) {
        if (v != father && !check[v]) {
            calc(v , u , status , d + 1);
        }
    }
}

void centroid(int u , int father) {
    DFS(u , u); 
    u = find_centroid(u , u , u); 
    check[u] = 1;
    //cerr << u << '\n';
    maxh = 0; 
    //cerr << u << '\n';
    for (auto v : adj[u]) {
        if (v != father && !check[v]) {
            calc(v , v , 0 , 1);
            calc(v , v , 1 , 1);
        }
    }
    vector<int> ans;
    ans.push_back(0);
    for (int i = 1 ; i <= maxh ; i++) {
        //cerr << get(i) - get(i - 1) << '\n';
        ans.push_back(get(i) - get(i - 1));
    }
    for (int i = 1 ; i <= maxh ; i++) {
        update(i , -ans[i]);
    }
    for (auto v : adj[u]) {
        if (!check[v]) centroid(v , u);
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k1 >> k2;
    update(0 , 1);
    for (int i = 1 ; i < n ; i++) {
        int u , v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }   
    centroid(1 , -1);
    cout << ans;
    return 0; 
}