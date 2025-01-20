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

void solve() {
    int n, k; cin >> n >> k;
    vector<pii> a(n + 1);
    for (int i = 1 ; i <= n ; i++) cin >> a[i].first;
    for (int i = 1 ; i <= n ; i++) cin >> a[i].second; 
    sort(a.begin() + 1 , a.end());
    int med = n/2;
    auto ok = [&](int X) -> bool {
        int pos = 0;   
        for (int i = 1 ; i <= n ; i++) {
            if (a[i].first <= X) pos = i;
            else break;
        }
        if (pos < med) return true;
        for (int i = 1 ; i <= n ; i++) {

        }
    };
    auto binary_search = [&]() -> void {
        int l = 1 , r = 1e9;
        while (l <= r) {
            int mid = (l + r)/2;
            if (ok(mid)) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
    };
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