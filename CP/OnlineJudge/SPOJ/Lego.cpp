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


int vis[N];
vector<vector<int>> adj(N);

void DFS(int u) {
    vis[u] = true; 
    for (int v : adj[u]) {
        if (!vis[v]) {
            DFS(v);
        }
    }
}

void solve() {
    int n; cin >> n;
    vector<int> x1(n), x2(n), y1(n), y2(n);
    map<int , vector<int>> mp;
    for (int i = 0 ; i < n ; i++) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        mp[y1[i]].push_back(i);
    }
    for (int i = 0 ; i < n ; i++) {
        for (auto j : mp[y2[i]]) {
            int fi = x1[j] , se = x2[j];
            if (!(se <= x1[i] || fi >= x2[i])) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    int ans = 0;
    for (int i = 0 ; i < n ; i++) {
        if (!vis[i]) {
            DFS(i);
            ans++;
        }
    }
    cout << ans;
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