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

void recur(int s , vi &v) {
    if (s == 1) return; 
    if (s % 2 == 0) {
        s /= 2; 
        v.push_back(s);
        recur(s , v);
    }
    else {
        s = s * 3 + 1; 
        v.push_back(s);
        recur(s , v);
    }
}

void solve() {
    int n; cin >> n;
    vi v;
    v.push_back(n); 
    recur(n , v);
    for (int x : v) cout << x << ' '; 
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
