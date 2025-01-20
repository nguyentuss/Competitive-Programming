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
    vector<int> a(n);
    int sum = 0;
    for (int &u : a) {
        cin >> u;
        sum += u;
    } 
    sort(a.begin() , a.end());
    for (int x : a) cerr << x << " ";
    int ans = n - 1;
    int x = a[0];
    for (int i = 1 ; i < n ; i++) {
        x += a[i];
        //cerr << i + 1 << " " << sum << " " << a[i] * (i + 1) << '\n';
        if (sum < a[i] * (i + 1)) {
            cout << ans; 
            return;
        }
        ans = n - (i + 1);
    }
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