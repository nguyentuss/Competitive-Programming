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
    vector<int> b(n + 1);
    for (int i = 1 ; i < n ; i++) cin >> b[i];
    vector<int> a(n + 1);
    a[0] = b[1]; 
    for (int i = 1 ; i < n - 1 ; i++) {
        a[i] = b[i] | b[i + 1];
        if ((a[i] & a[i - 1]) != b[i]) {
            cout << -1 << '\n';
            return; 
        }
    }
    a[n - 1] = b[n - 1];
    for (int i = 0 ; i < n ; i++) {
        cout << a[i] << " ";
    }
    cout << '\n';
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