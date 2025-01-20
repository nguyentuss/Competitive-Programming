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

// S - x - Y <= y <= S - x - X  
// S - x - Y <= y 



void solve() {
    int n , x , y; cin >> n >> x >> y;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i]; 
        sum += a[i];
    }
    sort(all(a));
    x = sum - x; 
    y = sum - y;
    // assert(x <= y);
    int ans = 0;
    for (int i = 0 ; i < n ; i++) {
        int right = upper_bound(a.begin() + i + 1 , a.end() , x - a[i]) - a.begin(); 
        int left = lower_bound(a.begin() + i + 1 , a.end(),  y - a[i]) - a.begin(); 
        // cerr << x - a[i] << ' ' << y - a[i] << ' ' << left << ' ' << right << '\n';
        ans += right - left;
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
