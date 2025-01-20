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
    int n, m; cin >> n >> m;
    vector<vector<int>> a(m);
    for (int i = 0 ; i < n ; i++) {
        int x , r; cin >> x >> r;
        x--;
        a[x].push_back(r);
    }
    vector<int> f(n);
    for (int i = 0 ; i < m ; i++) {
        sort(all(a[i]) , greater<int>());
        if (sz(a[i]) == 0) continue;
        if (a[i][0] < 0) continue;
        f[0] += a[i][0];
        for (int j = 1 ; j < sz(a[i]) ; j++) {
            // cerr << i << " " << j << " " << '\n';
            a[i][j] = a[i][j - 1] + a[i][j];
            if (a[i][j] < 0) break;
            f[j] += a[i][j];
        }
    }
    int ans = 0;
    for (int i = 0 ; i < n ;i++) {
        // cout << f[i] << " ";
        ans = max(ans , f[i]);
    }   
    cout << ans;
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