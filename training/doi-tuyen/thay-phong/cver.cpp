#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MAX_N (int) (1e5 + 7)
#define ii pair<int , int>

struct query {
    int v , k , id;
};

struct edge {
    int u , v , w;
};

bool cmp(edge &a , edge &b) {
    return a.w > b.w;
}

bool cmp1(query &a , query &b) {
    return a.k > b.k;
}

int sz[MAX_N];
int root[MAX_N];

void init() {
    for (int i = 1 ; i < MAX_N ; i++) {
        root[i] = i;
        sz[i] = 1;
    }
}

int find_root(int u) {
    if (root[u] == u) return u;
    else {
        return root[u] = find_root(root[u]);
    }
}

void unionset(int u , int v) {
    u = find_root(u);
    v = find_root(v);
    if (u != v) {
        if (sz[u] < sz[v]) swap(u , v);
        root[v] = u;
        sz[u] += sz[v];
    }
}

bool check(int u , int v) {
    u = find_root(u);
    v = find_root(v);
    return (u != v);
}

int n , q;
vector<edge> adj;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> q;
    init();
    for (int i = 1 ; i < n;i ++) {
        int u , v , w; cin >> u >> v >> w;
        adj.push_back({u , v , w});
    }
    sort(adj.begin() , adj.end() , cmp);
    vector<query> ask;
    for (int i = 0 ; i < q ; i++) {
        int v , k; cin >> k >> v;
        ask.push_back({v , k , i});
    }
    int pos = 0;
    sort(ask.begin() , ask.end() , cmp1);
    //for (auto x : ask) cerr << x.k << '\n';
    vector<ii> ans;
    for (auto x : ask) {
        while (adj[pos].w >= x.k && pos < adj.size()) {
            if (check(adj[pos].u , adj[pos].v)) {
                unionset(adj[pos].u , adj[pos].v); 
            }
            pos++;
        }
        //cerr << x.v << '\n';
        ans.push_back(ii(x.id , sz[find_root(x.v)] - 1));
    }
    //cerr << "DEBUG";
    sort(ans.begin() , ans.end());
    for (auto x : ans) cout << x.second << '\n';
    return 0;
}