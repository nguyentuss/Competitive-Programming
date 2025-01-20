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
    vector<int> a(n);
    vector<int> b(n);
    vector<pii> c(n);
    for (int i = 0 ; i < n ; i++) cin >> a[i]; 
    for (int i = 0 ; i < n ; i++) cin >> b[i];
    for (int i = 0 ; i < n ; i++) c[i] = {a[i] - b[i],b[i]};
    sort(all(c),greater<pii>());
    int ans = 0;
    bool change;
    for (int i = 0 ; i < n ; i++) {
        if (c[i].first > 0) {
            ans = ans + c[i].first + c[i].second;
        }
        else {
            ans += c[i].second;
        }
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
