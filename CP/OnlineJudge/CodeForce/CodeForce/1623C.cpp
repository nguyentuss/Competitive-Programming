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
    int mn = inf;
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i];
        mn = min(mn , a[i]);
    }
    
    int l = mn , r = 1e18;
    int ans = l;
    auto check = [&](int X) -> bool {
        vector<int> b; 
        b = a;
        vector<int> re(n);
        re[n-1] = 0;
        for (int i = n - 1 ; i >= 0 ;i --) {
            if (re[i] < X) {
                b[i] -= (X - re[i]);
                re[i] += (X - re[i]);
            }
            if (b[i] < 0) return false;
            if (i - 2 >= 0) {
                  int d = b[i]/3;
                if (i - 1 >= 0)
                re[i - 1] += d;
                if (i - 2 >= 0) 
                re[i - 2] += 2*d;
            }
        }
        for (int i = 0 ; i < n ; i++) {
            if (re[i] < X) return false;
        }
        return true;
    };
    while (l <= r) {
        int mid = (l + r) >> 1; 
        // cout << l << " " << mid << " " << r << '\n';
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
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