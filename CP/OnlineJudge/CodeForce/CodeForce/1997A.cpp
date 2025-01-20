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
    if (sz(s) == 1) {
        for (char c = 'a' ; c <= 'z' ; c++) {
            if (s[0] != c) {
                string x = ""; 
                x += c; 
                s = x + s;
                cout << s << '\n';
                return;
            }
        }
    }
    for (int i = 0 ; i < sz(s) - 1 ; i++) {
        if (s[i] == s[i + 1]) {
            for (char c = 'a' ; c <= 'z'; c++) {
                if (s[i] != c) {
                    string x = ""; 
                    x += c;
                    for (int j = 0 ; j <= i ; j++) {
                        cout << s[j];
                    }
                    cout << c; 
                    for (int j = i + 1; j < sz(s) ; j++) {
                        cout << s[j];
                    }
                    cout << '\n';
                    return;
                }
            }
        }
    }
    for (char c = 'a' ; c <= 'z' ; c++) {
            if (s[0] != c) {
                string x = ""; 
                x += c; 
                s = x + s;
                cout << s << '\n';
                return;
            }
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