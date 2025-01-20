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

int idx = 0;

void solve() {
    idx ++;
    int n; cin >> n;
    if (n >= 7) {
        if (n & 1) {
            cout << "Case #" << idx << ": Panda" << '\n';
        }
        else if (n >= 12) {
            cout << "Case #" << idx << ": Sheep" << '\n';
        }
        else {
            cout << "Case #" << idx << ": Draw" << '\n';
        }
    }
    else {
        cout << "Case #" << idx << ": Draw" << '\n';
    }
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