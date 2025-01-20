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
    int n , k; cin >> n >> k;
    map<int , int> mp;
    for (int i = 0 ; i < k ;i ++) {
        int x , y; cin >> x >> y; 
        mp[x] += y;
    }
    vector<int> ans;
    for (auto [x , y] : mp) {
        ans.push_back(y);
    }
    sort(all(ans) , greater<int>()); 
    int res = 0;
    for (int i = 0 ; i < min(sz(ans), n) ; i ++) {
        res += ans[i];
    }
    cout << res << '\n';
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