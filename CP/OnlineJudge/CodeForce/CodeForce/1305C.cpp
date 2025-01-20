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

// pigeonhole priciple
// (a[i] - a[j])%m => (a[i]%m - a[j]%m)%m
// n <= m , we can do with complexity O(m^2)
// else n > m
// applied pigeonhole priciple, at least 1 hole (1 -> m) consist 2 number in a
// then same module => (x - x)%m = 0%m  

void solve() { 
    int n , m; cin >> n >> m;
    vector<int> a(n);
    for (int &u : a) cin >> u; 
    if (n > m) return void(cout << 0); 
    int ans = 1;
    for (int i = 0 ; i < n ; i++) {
        for (int j = i + 1 ; j < n ; j++) {
            ans = (ans * abs(a[i] - a[j])%m)%m;
        }
    }
    cout << ans << '\n';
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