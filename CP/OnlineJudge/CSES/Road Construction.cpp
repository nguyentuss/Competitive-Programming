#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ii pair<int , int>
#define sz(x) (int)x.size()

const int N = 1e5 + 7;
const int inf = 1e18;

vector<tuple<int , int>> ed;
int sz[N] , root[N];
int mx_comps = 0 , num_comps = 0;

void init() {
    for (int i = 1 ; i < N ; i++) {
        root[i] = i;
        sz[i] = 1;
    }
}

int find_root(int u ) {
    return (u == root[u] ? u : find_root(root[u]));
}

bool merge(int u , int v) {
    u = find_root(u);
    v = find_root(v);
    if (u != v) {
        if (sz[u] < sz[v]) swap(u , v);
        root[v] = u;
        sz[u] += sz[v];
        //cerr << u << " " << v << " " << sz[u] << " " << sz[v] << '\n';
        mx_comps = max(mx_comps , sz[u]);
        num_comps--;
        return true;
    }
    return false;
}

void solve() {
    init();
    int n , m; cin >> n >> m;
    for (int i = 1 ; i <= m ; i++) {
        int u , v , c; cin >> u >> v;
        ed.push_back({u , v});
    }
    num_comps = n; 
    mx_comps = 1;
    for (auto [u , v] : ed) {
        merge(u , v);
        cout << num_comps << " " << mx_comps << '\n';
    }   
    return;
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}