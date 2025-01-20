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

void solve() {
    int n , m; cin >> n >> m;
    vector<vector<int>> adj(n); 
    // vector<int> a(n);
    // for (int i = 0 ; i < n ; i++) {
    //     cin >> a[i];
    // }
    for (int i = 0 ; i < m ; i++) {
        int u , v; cin >> u >> v;
        // u--; v--; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> num(n) , low(n);
    int timeDFS = 0;
    stack<int> st; 
    vector<vector<int>> two_edge_component(n);
    int scc = 0;
    function<void(int , int)> DFS = [&](int u , int father) {
        num[u] = low[u] = ++timeDFS;
        st.push(u);
        bool multiple_edge = false;
        for (int v : adj[u]) {
            if (v == father && !multiple_edge) {
                multiple_edge = true;
                continue; 
            }
            if (!num[v]) {
                DFS(v , u);
                low[u] = min(low[u] , low[v]); 
            }
            else {
                low[u] = min(low[u] , num[v]);
            }
        }
        if (low[u] == num[u]) {
            while (st.top() != u) {
                two_edge_component[scc].push_back(st.top());
                st.pop();
            }
            two_edge_component[scc++].push_back(st.top());
            st.pop();
        }
    };
    for (int i = 0 ; i < n ; i++) {
        if (!num[i]) {
            DFS(i,-1);
        }
    }
    cout << scc << '\n';
    for (int i = 0 ; i < scc ;i++) {
        cout << sz(two_edge_component[i]) << " ";
        for (int x : two_edge_component[i]) {
            cout << x << " ";
        }
        cout << '\n';
    }
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