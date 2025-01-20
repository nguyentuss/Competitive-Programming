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
    int n; cin >> n;
    auto Ask = [&](int l , int r) {
        if (r - l <= 1) return 0ll;                             
        cout << "? " << l + 1 << " " << r << endl;
        int got; cin >> got;
        return got;
    };
    int x = Ask(0 , n);
    if (x == 0) {
        cout << "! IMPOSSIBLE" << endl;
        return;
    }
    string s = "";
    for (int i = 0 ; i < n ; i++) {
        int y = Ask(i + 1 , n);
        if (y == x) {
            s += "1";
        }
        else {
            s += "0"; 
            if (y == 0) {
                s += string(x , '1'); 
                s.resize(n , '0');
                break;
            }
            x = y;
        }
    }
    cout << "! " << s << endl; 
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
