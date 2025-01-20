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
    int n; cin >> n;
    vector<int> a(n); 
    for (int i = 0 ; i < n ; i++) cin >> a[i];
    int ans = 0;
    int remain = 0;
    for (int i = 0 ; i < n ; i++) {
        int l = 1 , r = 1e18; 
        int mn = 0;
        while (l <= r) {
            int mid = (l + r)/2; 
            int pl_3 = (remain + mid)/3; 
            int pl_1 = mid - pl_3; 
            if (a[i] - pl_1 - 3*pl_3 <= 0) {
                mn = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        ans += mn;
        remain = (remain + mn)%3;
        //cout << ans << " ";
    }
    cout << ans;
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