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

/*
    a == b, can make difference between [x , x + a)
    a != b , can make difference between [x , x + gcd(a , b))
*/

void solve() {
    int n , x , y; cin >> n >> x >> y;
    vi a(n + 1);
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    int g = __gcd(x , y); 
    sort(a.begin() + 1 , a.end());
    for (int i = 1 ; i <= n ; i++) {
        a[i] = ((a[n] - a[i])/g)*g + a[i];
    }
    sort(a.begin() + 1 , a.end()); 
    int ans = a[n] - a[1];
    for (int i = 1 ; i < n ;i ++) {
        ans = min(ans , a[i] + g - a[i + 1]);
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