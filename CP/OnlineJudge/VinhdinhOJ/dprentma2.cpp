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

bool cmp(pii &a , pii &b) {
    return (a.second == b.second ? a.first < b.first : a.second < b.second);
}

void solve() {
    int n; cin >> n;
    vector<pii> a(n + 1);
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin() + 1, a.end(), cmp);
    // for (int i = 1 ; i <= n ; i++) {
        // cout << a[i].first << ' ' << a[i].second << '\n';
    // }
    map<int , int> dp;
    dp[0] = 0;
    for (int i = 1 ; i <= n ; i++) {
        dp[a[i].second] = dp[a[i - 1].second];
        auto it = dp.lower_bound(a[i].first);
        it--;   
        // cout << a[i].first << " " << it->first << '\n';
        dp[a[i].second] = max(dp[a[i].second], a[i].second - a[i].first + 1 + it->second);
    }
    cout << dp[a[n].second];
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
