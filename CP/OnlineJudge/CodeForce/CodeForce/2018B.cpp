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
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int i = 0 ; i < n ;i ++) {
        cin >> a[i];
    }
    map<int , int> mp;
    int cnt = n - 1;
    int tmp = n - 1;
    mp[n - 1] ++;
    int vl = -1;
    for (int i = 1 ; i < n ; i++) {
        //cerr << (n - 1) - i + (n - i)*i << " " << (n - i)*i << " " << max(0ll , a[i] - (a[i - 1] + 1)) << '\n';
        mp[(n - 1) - i + (n - i)*i] ++;
        mp[(n - i)*i] += max(0ll , a[i] - (a[i - 1] + 1));     
    }
    for (int i = 0 ; i < q ; i++) {
        int x; cin >> x;
        cout << mp[x] << " ";
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