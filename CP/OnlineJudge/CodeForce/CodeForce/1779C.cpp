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
    int n , m; cin >> n >> m;
    vector<int> a(n);
    for (int i = 0 ; i < n ; i++) cin >> a[i]; 
    m--;
    int pref = 0;
    for (int i = 0 ; i <= m ; i++) pref += a[i];
    int tmp = 0;
    int ans = 0;
    // after
    priority_queue<int> vc;
    for (int i = m + 1 ; i < n ; i++) {
        if (a[i] < 0);
        vc.push(-2*a[i]);
        tmp += a[i];
        if (tmp < 0) {
            while (!vc.empty()) {
                tmp += vc.top();
                ans ++;
                vc.pop();
                if (tmp >= 0) break;
            }
        }
    }
    // before
    min_heap<int> pq;
    pq.push(-2*a[m]);
    int sum = pref - a[m];
    for (int i = m - 1 ; i >= 0 ; i--) {
        if (sum < pref) {
            while (!pq.empty()) {
                pref += pq.top();
                ans ++;
                pq.pop(); 
                if (sum >= pref) break;
            }
        }
        sum -= a[i];
        if (a[i] > 0) pq.push(-2*a[i]);
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