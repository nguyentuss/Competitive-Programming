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
const int inf = 1e9 + 7;

void solve() {
    int n, m; cin >> n >> m;
    vector a(n , vector<int>(m));
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int mx = 0;
            if (i > 0) {
                mx = max(mx, a[i - 1][j]);
            }
            if (i < n - 1) {
                mx = max(mx, a[i + 1][j]);
            }
            if (j > 0) {
                mx = max(mx, a[i][j - 1]);
            }
            if (j < m - 1) {
                mx = max(mx, a[i][j + 1]);
            }
            a[i][j] = min(a[i][j], mx);
            cout << a[i][j] << " \n"[j == m - 1];
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