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
    vector<pair<int , int>> a(n);
    for (int i = 0 ; i < n ; i++) cin >> a[i].first >> a[i].second;
    int x1 , y1 , x2 , y2;
    cin >> x1 >> y1 >> x2 >> y2; 
    function<bool(int , int)> check = [&](int posx , int posy) {
        return (x2 <= posx && posx <= x1 && y2 <= posy && posy <= y1);
    };
    int ans = 0;
    for (int i = 0 ; i < n ;i ++) {
        ans += check(a[i].first , a[i].second);
    }
    cout << ans;
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