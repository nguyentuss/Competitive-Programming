//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
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

struct SCC {
    int n;
    vector<vector<int>> adj, g;
    vi low,num;
    vi flag;
    stack<int> st; 
    int timeDFS = 0 , scc = 0;
    SCC(int n): n(n), low(n), num(n), adj(n), g(n), flag(n) {} 

    void addEdge(int u , int v) {
        adj[u].push_back(v);
    }

    void DFS(int u) {
        low[u] = num[u] = ++timeDFS;
        st.push(u);
        for (int v : adj[u]) {
            if (!num[v]) {
                DFS(v);
                low[u] = min(low[u] , low[v]);
            }
            else {
                low[u] = min(low[u] , num[v]);
            }
        }
        // cerr << u << ' ' << low[u] << ' ' << num[u] << '\n';
        if (low[u] == num[u]) {
            while (st.top() != u) {
                g[scc].push_back(st.top());
                num[st.top()] = low[st.top()] = inf;
                st.pop();
            }
            g[scc++].push_back(st.top()); 
            num[st.top()] = low[st.top()] = inf;
            st.pop();
        }
    }

    void calc() {
        for (int i = 0 ; i < n ; i++) if (!num[i]) DFS(i);
        cout << scc << '\n';
        for (int i = scc - 1 ; i >= 0 ; i--) {
            cout << sz(g[i]) << ' '; 
            for (int x : g[i]) cout << x << ' '; 
            cout << '\n';
        }
    }
};

void solve() {
    int n , m; cin >> n >> m;
    vector<vector<int>> adj(n);
    SCC scc(n);
    for (int i = 0 ; i < m ; i++) {
        int u , v; cin >> u >> v;
        scc.addEdge(u , v);
    }
    scc.calc();
    
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test; 
    test = 1;
    // cin >> test;
    while (test--) {
        solve();
    }
 
}
