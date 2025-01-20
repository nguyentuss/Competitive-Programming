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

void solve() {
    int n , k; cin >> n >> k;
    vector<int> a(k); 
    for (int i = 0 ; i < k ; i++) cin >> a[i];
    sort(a.begin() , a.end()); 
    int ans = 0;
    int cnt = 0;
    for (int i = 0 ; i < sz(a) - 1 ; i++) {
        ans = ans + a[i] - 1;
        cnt += a[i];
    } 
    cout << ans + cnt << '\n';
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