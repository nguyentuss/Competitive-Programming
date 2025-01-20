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
    int n; cin >> n;
    vector<tuple<int , int , int>> q;
    map<int , int> mp[n];
    auto add = [&](int x , int y) -> void {
        mp[x][y]++; 
        mp[y][x]++;
    };
    for (int i = 0 ; i < n - 2; i++) {
        int a , b , c; cin >> a >> b >> c; 
        a--; b--; c--;
        q.push_back({a , b , c});
        add(a , b); 
        add(a , c);
        add(b , c);
    }
    // for (int i = 0 ; i < n ;i ++) cerr << sz(mp[i]) << " ";
    int st;
    vector<set<int>> adj(n);
    for (int i = 0 ; i < n ; i++) {
        if (sz(mp[i]) == 2) {
            st = i;
            for (auto [j , cnt] : mp[i]) {
                if (sz(mp[j]) == 3) {
                    adj[i].insert(j); 
                    adj[j].insert(i);
                }           
            }
        }
        else {
            for (auto [j , cnt] : mp[i]) {
                if (cnt == 2) {
                    adj[i].insert(j);
                    adj[j].insert(i);
                }
            }
        }
    }
    vector<int> vis(n);
    function<void(int)> dfs = [&](int u) {
        vis[u] = true; 
        cout << u + 1 << " ";
        for (int v : adj[u]) {
            if (!vis[v]) dfs(v); 
        }
    };
    dfs(st);
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test; 
    test = 1;
    //cin >> test;
    while (test--) {
        solve();
    }

}