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
    vector<int> a(n + 1);
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
    }
    vector<int> pref(n + 1);
    for (int i = 1 ; i <= n ; i++) {
        pref[i] = max(pref[i - 1] , a[i]);
    }
    vector<int> suf(n + 2 , inf);
    for (int i = n ; i >= 1 ; i--) {
        suf[i] = min(suf[i + 1] , a[i]);
    }
    int l = 1;
    vector<int> b(n + 1);
    for (int i = 1 ; i <= n ; i++) {
        if (pref[i] <= suf[i + 1]) {
            for (int j = l ; j <= i ; j++) {
                b[j] = pref[i];
            }
            l = i + 1;
        }
    }
    for (int i = 1 ; i <= n ; i++) cout << b[i] << " ";
    cout << endl;
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

