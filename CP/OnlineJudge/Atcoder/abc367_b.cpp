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
    reverse(all(s)); 
    bool on = false;
    string t = "";
    int cnt = 0;
    for (int i = 0 ; i < sz(s) ; i++) {
        if (s[i] != '0') {
            if (on) on = false;
            if (!on) {
                if (cnt == 3) {
                    cnt = 0;
                }
                else t += s[i];
            }
        }
        else {
            if (i == 0) {
                on = true;
            }
            if (!on) t += s[i];
            else cnt++;
        }
    }
    reverse(all(t));
    cout << t;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test; 
    test = 1;
    //cin >> test;
    while (test--) {
        solve();
    }

}