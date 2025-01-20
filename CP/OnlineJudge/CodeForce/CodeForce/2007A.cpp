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
11 12 13
15 16 17
19 20 21
23 24 25*/

void solve() {
    int l , r ; cin >> l >> r;
    int ans = 0;
    if (l % 2 == 0) l++; 
    int cnt = 0;
    while (true) {
        if (r - l + 1 >= 3) cnt++;
        if (l > r) break;
        l += 4;
    }
    cout << cnt << '\n';
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