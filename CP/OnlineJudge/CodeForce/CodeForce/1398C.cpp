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
    int n; cin >> n;
    string s; cin >> s;
    s = " " + s; 
    vector<int> f(n+1);
    for (int i = 1 ; i <= n ; i++) {
        f[i] = f[i - 1] + s[i] - '0';
    }
    map<int , int> mp;
    mp[0] = 1;
    int ans = 0;
    for (int i = 1 ; i <= n ; i++) {
        ans = ans + mp[f[i] - i];
        mp[f[i] - i] ++; 
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