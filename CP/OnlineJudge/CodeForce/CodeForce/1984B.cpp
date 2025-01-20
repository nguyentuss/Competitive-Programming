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
    int x; cin >> x;
    int a = 0;
    int b = 0;
    int cc = 0;
    while (x) {
        int d = x % 10; 
        x /= 10;
        if (x == 0) {
            if (d > 1) {
                cout << "NO\n";
                return;
            }
        }
        if (cc) d --;
        if (d < 0 || d == 9) {
            cout << "NO\n"; 
            return;
        }
        cc = 1;
    }
    cout << "YES\n";
    return ;
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