//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
const int inf = 1e9;
const int N = 2e5 + 7;

void solve() {
    int n; cin >> n;
    vector<vi> adj(n);
    vi a(n), dp(3);
    int cnt = 0;
    for (int i = 1 ; i < n ; i++) {
        int u , v; cin >> u >> v;
        u--; v--; 
        adj[u].push_back(v); 
        adj[v].push_back(u);
    }
    auto DFS = [&](int u , int f , auto && DFS) -> void {
        int tmp = 0;
        for (int v : adj[u]) {
            if (v != f) {
                tmp++;
                DFS(v , u , DFS);
            }
        }   
        if (!tmp) {
            dp[a[u]]++;
        } 
        else if (u != 0 && a[u] == 2) {
            cnt++;
        }
    };
    for (int i = 0 ; i < n ; i++) {
        char x; cin >> x; 
        if (x != '?') a[i] = x - '0'; 
        else a[i] = 2;
    }
    DFS(0 , -1 , DFS);
    if (a[0] == 0) {
        cout << (dp[2]/2 + dp[2]%2) + dp[1] << '\n';
    }
    else if (a[0] == 1) {
        cout << (dp[2]/2 + dp[2]%2) + dp[0] << '\n';
    }
    else if (a[0] == 2) {
        if (dp[1] == dp[0]) {
            cout << dp[1] + (dp[2] + (cnt%2))/2 << '\n';
        }
        else {
            cout << max(dp[1] , dp[0]) + dp[2]/2 << '\n';
        }
    }

}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test; 
    test = 1;
    cin >> test;
    while (test--) {
        solve();
    }

}