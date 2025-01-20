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
const int MAX_N = 3e5 + 7;
const int MOD = 1e9 + 7;

int root[MAX_N];
int sz[MAX_N];
int comp;
bool ask[MAX_N];
stack<ii> st;
int ans[MAX_N];
int n , m;
vector<ii> IT[4 * MAX_N];
map<ii , int> pos; 

void init() {
    for (int i = 1 ; i < MAX_N ; i++) {
        root[i] = i;
        sz[i] = 1;
    }
    comp = n;
}

int find_root(int u) {
    if (u == root[u]) return u;
    else return find_root(root[u]);
}

void rollback(int cnt) {
    if (st.empty()) return;
    //cout << cnt << " " << st.size() << '\n';
    while (cnt--) {
        auto x = st.top();
        st.pop();
        comp++;
        root[x.se] = x.se;
        sz[x.fi] -= sz[x.se];
    }
}

int union_set(int u , int v) {
    u = find_root(u);
    v = find_root(v);
    if (u != v) {
        comp--;
        if (sz[u] < sz[v]) swap(u , v);
        st.push(ii(u , v));
        root[v] = u;
        sz[u] += sz[v];
        return 1;
    }
    return 0;
}

void update(int id , int l , int r , int L , int R , ii val) {
    //cerr << id << '\n';
    if (l > R || r < L) return;
    if (l <= L && R <= r) {
        IT[id].push_back(val);
        return;
    }
    int mid = (L + R) >> 1;
    update(id << 1 , l , r , L , mid , val);
    update((id << 1)  + 1 , l , r , mid + 1 , R , val);
}

int DFS(int id , int l , int r) {
    int ret = 0;
    for (auto x : IT[id]) {
        ret += union_set(x.fi , x.se);
    }
    if (l == r) {
        ans[l] = comp;
        return ret;
    }
    int mid = (l + r)>>1;
    rollback(DFS(id << 1, l , mid));
    rollback(DFS((id << 1) + 1 , mid + 1 , r));
    return ret;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen("connect.in","r",stdin);
    freopen("connect.out","w",stdout);
    cin >> n >> m;
    if (m == 0) {
        return 0;
    }
    init();
    for (int i = 1 ; i <= m ; i++) {
        char c; cin >> c;
        if (c == '?') {
            ask[i] = 1; 
            continue;
        }
        int u , v; cin >> u >> v;
        if (u < v) swap(u , v);
        if (c == '+') {
            pos[ii(u , v)] = i;
        }
        else {
            auto it = pos.find(ii(u , v));
            update(1 , it->second , i , 1 , m , ii(u , v));
            pos.erase(it);
        }
    }
    for (auto it : pos) {
        update(1 , it.se , m , 1 , m , it.fi);
    }
    DFS(1 , 1 , m);
    //cerr << "DEBUG";
    for (int i = 1 ; i <= m ; i++) {
        if (ask[i]) {
            cout << ans[i] << '\n';
        }
    }
    return 0;
}