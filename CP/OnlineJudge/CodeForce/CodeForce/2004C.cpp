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
    int n, k; cin >> n >> k;
    vector<int> a(n); 
    for (int &u : a) cin >> u;
    sort(all(a));
    reverse(all(a));
    for (int i = 0 ; i < n - (n%2 ? 1 : 0) ; i+=2) {
        int c = a[i] - a[i + 1]; 
        k -= c;
    }
    cout << max(0ll , -k) + (n % 2 ? a[n-1] :0) << '\n';
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);g
    int test; 
    test = 1;
    cin >> test;
    while (test--) {
        solve();
    }

}