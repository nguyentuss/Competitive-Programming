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
    vector<int> a(n + 1);
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
    }
    string s; cin >> s;
    s = " " + s; 
    int l = -1e9 , r = 1e9;
    int vis1 = false , vis2 = false;
    for (int i = 5 ; i <= n ; i ++) {
        if (s[i] == '0' && s[i - 1] == '1' && s[i - 2] == '1' && s[i - 3] == '1' && s[i - 4] == '1') {
            r = min({r , a[i - 1] - 1 , a[i - 2] - 1 , a[i - 3] - 1, a[i - 4] -1, a[i]-1});
        }
        if (s[i] == '1' && s[i - 1] == '0' && s[i - 2] == '0' && s[i - 3] == '0' && s[i - 4] == '0') {
            l = max({l , a[i] + 1 , a[i - 1] + 1 , a[i - 2] + 1 , a[i - 3] + 1 , a[i - 4] + 1});
        }
    }
    cout << l << " " << r;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test; 
    test = 1;
    //  cin >> test;
    while (test--) {
        solve();
    }

}