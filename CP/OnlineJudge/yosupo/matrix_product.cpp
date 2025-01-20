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
const int mod = 998244353;

void solve() {
    int n, m , k;cin >> n >> m >> k;
    vector<vi> a(n , vi(m));
    vector<vi> b(m , vi(k)); 
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m; j ++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0 ; i < m ; i++) {
        for (int j = 0 ; j < k ; j++) {
            cin >> b[i][j];
        }
    }
    vector<vi> c(n , vi(k));
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            for (int h = 0 ; h < k ; h++) {
                (c[i][h] += a[i][j] * b[j][h])%=mod;
            }
        }
    }
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < k ; j++) {
            cout << c[i][j] << ' '; 
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
