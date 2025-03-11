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
    // int = -2^31 -1 <= x <= 2^31 - 1
    // long long = -2^63 - 1 <= x <= 2^63 - 1
    string s; cin >> s;
    int mx = -1; // luu gia tri
    int n = sz(s) - 1;
    /*
        string => chuỗi kí tự 
        kí tự => 0 -> 255 (ASCII)
        c - '0'
        <=> 56 - 48 = 8
    */
    function<void(int)> calc = [&](int i) {
        if (i == n + 1) return;
        mx = max(mx, (ll) (s[i] - '0'));
        calc(i + 1);
    };
    calc(0);
    cout << mx;
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
