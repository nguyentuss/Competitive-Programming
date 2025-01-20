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

//5 15
// 1 5

void solve() {
    int k, l1 , r1, l2 , r2; cin >> k >> l1 >> r1 >> l2 >> r2; 

    int p = 1; 
    int ans = 0;
    while (p <= r2) {
        if (p > r2) break;
        int nl = l2 / p + (l2 % p ? 1 : 0);
        int nr = r2 / p;
        if (!nl && !nr) continue;
        // cout << p << ' ' << nl << ' ' << nr << ' ' << l1 << ' ' << r1 << ' ' << max(0ll, min(r1 , nr) - max(l1 , nl) + 1) << '\n';
        ans += max(0ll, min(r1 , nr) - max(l1 , nl) + 1);
        p *= k;
    }
    cout << ans << '\n';
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
