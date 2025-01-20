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

vi KMP(string &s) {
    int n = sz(s);
    vi pi(n);
    for (int i = 1 ; i < n ; i++) {
        int j = pi[i - 1]; 
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

void solve() {
    string s; cin >> s;
    int n = sz(s);
    vi pi = KMP(s);
    vi ok(n + 1);
    auto compute = [&]() -> int {
        int x = pi[n - 1];
        int cnt = 1;
        while (x) {
            ok[x] = true;
            cnt++;
            x = pi[x - 1];
        }
        return cnt;
    };
    int ans = compute();
    string t = "";
    for (int i = 0 ; i < pi[n - 1] ; i++) {
        t += s[i];
    }
    int m = sz(t);
    if (!m) {
        cout << 1 << '\n';
        cout << n << ' ' << 1 << '\n';
        return;
    }
    vector<int> f(n + 1);
    int j = 0;
    for (int i = 0 ; i < n ; i++) {
        while (j > 0 && t[j] != s[i]) {
            j = pi[j - 1];
        }
        if (s[i] == t[j]) j++;
        cerr << j << '\n';
        f[j]++;
        if (j == m) {
            j = pi[j - 1];
        }
    }
    for (int i = n ; i > 0 ; i--) {
        if (pi[i - 1]) {
            f[pi[i - 1]] += f[i];
        }
    }
    cout << ans << '\n';
    for (int i = 1 ; i <= n ; i++) {
        if (ok[i]) {
            cout << i << ' ' << f[i] << '\n';
        }
    }
    cout << n << ' ' << 1 << '\n';
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test; 
    test = 1;
    // cin >> test;
    while (test--) {
        solve();
    }
 
}
