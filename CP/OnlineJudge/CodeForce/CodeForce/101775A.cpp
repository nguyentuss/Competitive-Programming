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

int idx = 0;

void solve() {
    idx ++;
    int a , b , c , d , e; cin >> a >> b >> c >> d >> e; 
    int n; cin >> n;
    vi v(n);
    int ans = 0; 
    for (int i = 0 ; i < n ; i ++) {
        int x; cin >> x;
        if (1 <= x && x <= 48) ans += a; 
        if (49 <= x && x <= 56) ans += b;
        if (57 <= x && x <= 60) ans += c; 
        if (61 <= x && x <= 62) ans += d; 
        if (x == 63) ans += e;
    }
    cout << "Case #" << idx << ": " << ans * 10000 << '\n';
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