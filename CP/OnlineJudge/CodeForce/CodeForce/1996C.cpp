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
    int n , q; cin >> n >> q;
    string a , b; cin >> a >> b; 
    vector<vi> f(n + 1 , vi(26 , 0));
    vector<vi> g(n + 1 , vi(26 , 0));
    a = " " + a; 
    b = " " + b;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 0 ; j < 26 ; j++) {
            f[i][j] = f[i - 1][j] + ((a[i] - 'a') == j ? 1 : 0); 
            g[i][j] = g[i - 1][j] + ((b[i] - 'a') == j ? 1 : 0); 
        }
    }
    while (q--) {
        int l , r; cin >> l >> r;
        int ans = 0;
        int c = 0 , d = 0;
        for (int i = 0 ; i < 26 ; i++) {
            if (f[r][i] - f[l - 1][i] - (g[r][i] - g[l - 1][i]) > 0) c = c + f[r][i] - f[l - 1][i] - (g[r][i] - g[l - 1][i]); 
            else d = d + f[r][i] - f[l - 1][i] - (g[r][i] - g[l - 1][i]);
        }
        cout << c << '\n';
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