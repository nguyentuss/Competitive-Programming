//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
typedef pair<int, int> ii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

void solve() {
    string s; cin >> s;
    int n = sz(s);
    int num_1 = 0 , num_0 = 0;
    for (auto c : s) {
        if (c == '0') num_0 ++;
        else num_1 ++;
    }
    int cnt = 0;
    for (auto c : s) {
        if (c == '0') {
            if (num_1) {
                num_1--;
            }
            else {
                cout << n - cnt << '\n';
                return ;
            }
        }
        else {
            if (num_0) {
                num_0--;
            }
            else {
                cout << n - cnt << '\n';
                return;
            }
        }
        cnt++;
    }
    cout << 0 << '\n';
}

main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
    int test; cin >> test;
    while (test--) {
        solve();
    }
}