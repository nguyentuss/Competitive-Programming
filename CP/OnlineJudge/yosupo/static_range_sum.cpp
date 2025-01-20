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
const int N = 5e5 + 7; 

struct FT {
    int n;
    vi f;
    FT(int n): n(n), f(n){};

    void update(int i , int val) {
        for ( ; i < n ; i |= i + 1) {
            f[i] += val;
        }
    }

    int query(int i) {
        int ans = 0;
        for (; i > 0 ; i &= i - 1) {
            ans += f[i - 1];t
        }
        return ans;
    }
};

void solve() {
    int n , q; cin >> n >> q;
    FT ft(n);
    for (int i = 0 ; i < n ; i++) {
        int x; cin >> x;
        ft.update(i , x);
    }
    while (q--) {
        int l , r; cin >> l >> r;
        cout << ft.query(r) - ft.query(l) << '\n';
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
