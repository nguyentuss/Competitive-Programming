#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ii pair<int , int>
#define sz(x) (int)x.size()

const int N = 1e5 + 7;
const int inf = 1e18;

vector<tuple<int , int , int>> ed;
int sz[N] , root[N];

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
        return true;
    }
    return false;
}

void solve() {
    init();
    int n , m; cin >> n >> m;
    for (int i = 1 ; i <= m ; i++) {
        int u , v , c; cin >> u >> v >> c;
        ed.push_back({u , v , c});
    }
    sort(ed.begin() , ed.end() , [](auto const &a , auto const &b) {
        return get<2>(a) < get<2>(b);
    });
    int ans = 0;
    int cnt_roads = 0;
    for (auto [u , v , c] : ed) {
        if (merge(u , v)) {
            ans += c;
            cnt_roads++;
        }   
    }   
    if (cnt_roads == n - 1) cout << ans;
    else cout << "IMPOSSIBLE";
    return;
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}