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

vi KMP(vector<int> &s) {
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
    int n , w; cin >> n >> w;
    vector<int> s;
    vector<int> t;
    vector<int> difa(n), difb(w);
    vector<int> a(n), b(w);
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i];
        if (i) {
            difa[i - 1] = a[i] - a[i - 1];
            s.push_back(difa[i - 1]);
        }
    }
    for (int i = 0 ; i < w ; i++) {
        cin >> b[i];
        if (i) {
            difb[i - 1] = b[i] - b[i - 1];
            t.push_back(difb[i - 1]);
        }
    }
    if (w == 1) {
        cout << n << '\n';
        return;
    }
    vi pi = KMP(t);
    int j = 0;
    int ans = 0;
    // cout << sz(t) << " " << sz(s) << '\n';
    for (int i = 0 ; i < n-1 ; i++) {
        // assert(j < sz(t));
        while (j > 0 && t[j] != s[i]) {
            j = pi[j - 1];
        }
        if (t[j] == s[i]) j++;
        if (j == w-1) {
            ans++; 
            j = pi[j-1];
        }
    }
    cout << ans;
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
