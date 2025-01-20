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
    string s; cin >> s;
    vector<int> cnt(26);
    for (int i = 0 ; i < n ; i++) {
        cnt[s[i] - 'a']++;
    }
    int mx = 0;
    char t;
    int mn = inf;
    char v;
    for (int i = 0 ; i < 26 ; i++) {
        if (!cnt[i]) continue;;
        if (mx < cnt[i]) {
            mx = cnt[i]; 
            t = i + 'a';
        }
    }
    for (int i = 0 ; i < 26 ; i++) {
        if (!cnt[i]) continue;
        if ((i + 'a') != t) {
            if (mn > cnt[i]) {
                mn = cnt[i];
                v = i + 'a';
            }
        }
    }
    // cerr << t << " " << v << '\n';
    bool stat = false;
    for (int i = 0 ; i < n ;i ++) {
        if (!stat && s[i] == v) {
            stat = true; 
            cout << t;
        }
        else cout << s[i];
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
