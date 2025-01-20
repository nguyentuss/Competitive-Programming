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
    int n , m , q; cin >> n >> m >> q;
    vector<int> a(n);
    vector<int> b(m);
    vector<int> pos(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i]; 
        a[i]--; 
        pos[a[i]] = i;
    }
    vector<set<int>> s(n); 
    for (int i = 0 ; i < m ; i++) {
        cin >> b[i]; 
        b[i]--;
        s[b[i]].insert(i);
    }
    for (int i = 0 ; i < n ; i++) s[i].insert(m);
    int fail = 0;
    vector<int> val(n); 
    for (int i = 0 ; i < n ; i++) val[i] = *s[a[i]].begin();
    for (int i = 0 ; i < n - 1 ; i++) {
        fail += (val[i] > val[i + 1]);
    }
    cout << (fail ? "TIDAK":"YA") << '\n';
    auto update = [&](int i) {
        if (i > 0) {
            fail -= (val[i - 1] > val[i]);
        }
        if (i < n - 1) {
            fail -= (val[i] > val[i + 1]);
        }
        val[i] = *s[a[i]].begin();
        if (i > 0) {
            fail += (val[i - 1] > val[i]);
        }
        if (i < n - 1) {
            fail += (val[i] > val[i + 1]);
        }
    };
    while (q--) {
        int i , v; cin >> i >> v;
        i--; v--;
        s[b[i]].erase(i);
        int prev = b[i]; 
        b[i] = v;
        s[b[i]].insert(i);
        update(pos[prev]);
        update(pos[b[i]]);    
        cout << (fail ? "TIDAK":"YA") << '\n';
        //cerr << "YES\n";
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