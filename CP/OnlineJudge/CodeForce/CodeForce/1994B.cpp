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
    string s , t; cin >> s >> t;
    if (s[0] == '0' && t[0] == '1') return void(cout << "NO\n");
    int num0 = (s[0] == '0' ? 1 : 0) , num1 = (s[0] == '1' ? 1 : 0); 
    for (int i = 1 ; i < n ; i++) {
        if (s[i] == '0') num0++; 
        else num1++; 
        if (s[i] == '0' && t[i] == '1') {
            if (!num1) return void(cout << "NO\n");
        }
        else if (s[i] == '1' && t[i] == '0') {
            if (!num1) return void(cout << "NO\n");
        }
    }
    cout << "YES\n";
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