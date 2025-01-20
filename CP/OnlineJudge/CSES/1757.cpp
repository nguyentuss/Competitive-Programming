//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define int long long	
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e18 + 7;

vector<int> adj[N];

void solve() {
    int n , m; cin >> n >> m;
    vector<int> out(n);
    for (int i = 0 ; i < m ; i++) {
        int u , v; cin >> u >> v;
        u--; v--;
        out[u]++;
        adj[v].push_back(u);
    }
    priority_queue<int> pq;
    vector<int> ans;
    for (int i = 0 ; i < n ; i++) {
        if (!out[i]) pq.push(i);
    }
    while (!pq.empty()) {
        int u = pq.top(); 
        pq.pop();
        ans.push_back(u);
        for (auto v : adj[u]) {
            out[v]--;
            if (!out[v]) {
                pq.push(v);
            }
        }
    }
    reverse(ans.begin() , ans.end());
    for (auto x : ans) cout << x + 1 << " "; 
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test = 1; 
    //cin >> test; 
    while (test--) {
       solve();
    }
}