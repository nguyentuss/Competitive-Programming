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
    string a , b; cin >> a >> b;
    int ans = 0;
    for (int i = 0 ; i < sz(b) ; i++) {
        int k = i;
        for (int j = 0 ; j < sz(a) && k < sz(b) ; j++) {
            if (b[k] == a[j]) {
                k++;
            }
        }
        //if (i == 0) cout << k << '\n';
        ans = max(ans , k - i);
    }
    //cerr << ans << '\n';
    cout << sz(a) + sz(b) - ans << '\n';
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