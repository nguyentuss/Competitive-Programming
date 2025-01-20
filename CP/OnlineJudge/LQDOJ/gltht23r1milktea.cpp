#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define le(x) (x << 1ll)
#define ri(x) ((x << 1ll) + 1)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
const int inf = 1e9;
const int N = 4e5 + 7;

int a[N] , num[N] , low[N];
int id[N] , vis[N];
ll b[N];
vector<pii> trace;
vector<pii> edge;
vector<int> adj[N];
int timeDFS = 0;
stack<int> st;
int scc = 0;
set<int> s[N];

void DFS(int u , int father) {
    num[u] = low[u] = ++timeDFS;
    st.push(u);
    bool multiple_edge = false;
    for (int v : adj[u]) {
        if (v == father && !multiple_edge) {
            multiple_edge = true;
            continue; 
        }
        if (!num[v]) {
            trace.push_back(pii(u , v));
            DFS(v , u);
            low[u] = min(low[u] , low[v]); 
        }
        else {
            if (num[v] > low[u]) trace.push_back(pii(v , u));
            low[u] = min(low[u] , num[v]);
        }
    }
    if (low[u] == num[u]) {
        while (st.top() != u) {
            id[st.top()] = scc;
            b[scc] += a[st.top()];
            st.pop();
        }
        b[scc] += a[st.top()];
        id[st.top()] = scc++;
        st.pop();
    }
}

void solve() {
    int n , m; cin >> n >> m;
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i];
    }
    for (int i = 0 ; i < m ; i++) {
        int u , v; cin >> u >> v;
        u--; v--; 
        adj[u].push_back(v);
        adj[v].push_back(u);
        edge.push_back(pii(u , v));
    }

    for (int i = 0 ; i < n ; i++) {
        if (!num[i]) {
            DFS(i,-1);
        }
    }
    vector<vector<tuple<int , int , int>>> g(scc);
    for (auto& [x , y] : edge) {
        int node_1 = id[x];
        int node_2 = id[y]; 
        if (node_1 != node_2) {
            g[node_1].push_back({node_2 , y , x});
            g[node_2].push_back({node_1 , x , y});
        }
    }
    ll mx = 0;
    int tmp;
    for (int i = 0 ; i < scc ; i++) {
        if (mx < b[i]) tmp = i;
        mx = max(mx , b[i]);
    }
    queue<int> q;
    q.push(tmp);
    vis[tmp] = true;
    vector<pii> trace1;
    while (!q.empty()) {
        int u = q.front(); 
        q.pop(); 
        for (auto& [v , x1 , x2] : g[u]) {
            if (!vis[v]) {
                s[x1].insert(x2);
                vis[v] = true;
                q.push(v);
            }
        }
    }   
    cout << mx << '\n';
    vector<pii> ans;
    for (auto [u , v] : trace) {
        if (s[v].find(u) == s[v].end()) {
            s[u].insert(v);
        }
    }
    for (auto &[u , v] : edge) {
        if (s[u].find(v) == s[u].end()) {
            cout << v + 1 << " " << u + 1 << '\n';
        }
        else {
            cout << u + 1 << " " << v + 1 << '\n';
        }
    }   
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test; 
    test = 1;
    // cin >> test;
    while (test--) {
        solve();
    }
}