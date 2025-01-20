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

const int inf = 1e18 + 7;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n) , b(n) , d(n) , c(m); 
    int mx = 0;
    for (int &u : a) cin >> u , mx = max(mx , u);
    for (int &u : b) cin >> u;
    for (int &u : c) cin >> u;
    vector<int> f(2*mx + 3 , inf);
    for (int i = 0 ; i < n ; i++) 
        f[a[i]] = min(f[a[i]] , a[i] - b[i]);
    for (int i = 1 ; i <= mx ; i++) {
        f[i] = min(f[i] , f[i - 1]);
    }
    vector<int> dp(2*mx + 3 , 0);
    for (int i = 1 ; i <= mx ; i++) {
        if (i - f[i] < 0) continue;
        dp[i] = max(dp[i] , dp[i - f[i]] + 1);
    }
    int ans = 0;
    for (int i = 0 ; i < m ; i++) {
        if (c[i] <= mx) {
            ans += dp[c[i]]; 
            continue;
        }
        int res = (c[i] - mx + f[mx] - 1)/f[mx];
        c[i] -= res*f[mx];
        ans += res;
        //cerr << res << " ";
        ans += dp[c[i]];
    }
    cout << 2*ans;
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