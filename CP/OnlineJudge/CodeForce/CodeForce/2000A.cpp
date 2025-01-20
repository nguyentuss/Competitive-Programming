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
    string s; cin >> s;
    if (s[0] != '1' || s[1] != '0') {
        cout << "NO\n";
        return;
    }
    if (sz(s) > 2) {
        if (sz(s) == 3) {
            if (s[2] == '1' || s[2] == '0') {
                cout << "NO\n";
            }
            else {
                cout << "YES\n";
            }
        }
        else {
            if (s[2] == '0') {
                cout << "NO\n";
            }
            else {
                cout << "YES\n";
            }
        }
    }
    else {
        cout << "NO\n";
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