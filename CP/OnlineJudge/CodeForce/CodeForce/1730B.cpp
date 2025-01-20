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
const double esp = 1e-6;

void solve() {
    int n; cin >> n;
    vector<int> a(n); 
    for (int i = 0 ; i < n ; i++) cin >> a[i]; 
    vector<int> t(n); 
    for (int i = 0 ; i < n ; i++) cin >> t[i]; 
    
    function<double(double)> cost = [&](double p) {
        double ans = 0;
        for (int i = 0 ; i < n ; i++) {
            ans = max(ans , t[i] + abs(a[i] - p));
        }
        return ans;
    };

    double l = 0, r = 1e9; 
    while (r - l > esp) {
    // for (int K = 0 ; K < 222 ; K++) {
        double len = r - l; 
        len /= 3.0;
        double m1 = l + len;
        double m2 = r - len; 
        if (cost(m1) < cost(m2)) {
            r = m2;
        }
        else l = m1;
    }
    cout << fixed << setprecision(10) << l << '\n';
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