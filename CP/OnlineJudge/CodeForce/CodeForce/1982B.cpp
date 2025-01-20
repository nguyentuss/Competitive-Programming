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
    int x , y , k; cin >> x >> y >> k;
    while (x >= y) {
        if (x % y == 0) {
            x++; 
            k--;
                if (!k) {
                cout << x << '\n';
                return;
            }
            continue;
        }
        int val = y - (x % y);
        if (k < val) {
            cout << x + k << '\n';
            return;
        }
        x = x + val;
        while (x % y == 0) {
            x /= y;
        }
        k -= val;
        //cerr << k << " " << x << '\n';
        if (!k) {
            cout << x << '\n';
            return;
        }
    }
    //cerr << k << '\n';
    if (!k) {
        cout << x << '\n';
        return;
    }
    if (x != 1) {
        if (y - x > k) {
            cout << x + k << '\n';
            return;
        }
        k = k - (y - x);
        x = x + (y - x); 
        x /= y;
        //cerr << k << '\n';
        if (!k) {
            cout << x << '\n';
            return;
        }
    }
    int vv = k % (y - 1); 
    cout << 1 + vv << '\n';
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