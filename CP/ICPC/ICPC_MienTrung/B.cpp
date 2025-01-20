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
const int MASK = 1 << 20;

void solve() {
    int n , k; cin >> n >> k;
    vector<int> a(n); 
    for (int i = 0 ; i < n ; i++) cin >> a[i]; 
    vector<int> f(MASK); 
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            f[a[i] & a[j]]++;
        }
    }
    for (int i = 0 ; i < 20 ; i++) {
        for (int mask = 0 ; mask < MASK ; mask++) {
            if (mask & (1 << i)) {
                f[mask] += f[mask^(1 << i)];
            }
        }
    }
    int cnt = 0;
    int q1 = -1 , q2 = -1 , q3 = -1 , q4 = -1;
    auto calc = [&]() -> bool {
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < n ; j++) {
                int c = (MASK - 1)^(a[i] & a[j]);
                if (cnt + f[c] >= k) {
                    q1 = i , q2 = j;
                    return true;
                }
                cnt += f[c];
            }
        }
        return false;
    };
    if (!calc()) {
        cout << -1;
        return;
    }
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            if ((a[q1] & a[q2] & a[i] & a[j]) == 0) {
                cnt++;
                if (cnt == k) {
                    q3 = i , q4 = j;
                }
            }
        }
    }
    cout << q1 + 1 << " " << q2 + 1 << " " << q3 + 1 << " " << q4 + 1 << '\n';
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test; 
    test = 1;
    //cin >> test;
    while (test--) {
        solve();
    }

}