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

struct RMQ {
    int n;
    vector<vi> jmp;
    RMQ(int n): n(n), jmp(n,vi(22,inf)){}

    void init(vi &a) {
        for (int i = 0 ; i < n ; i++) {
            jmp[i][0] = a[i];
        }
        for (int k = 1 ; k < 22 ; k++) {
            for (int i = 0 ; i < n ; i++) {
                if (i + (1 << k) - 1 >= n) break;
                jmp[i][k] = min(jmp[i][k - 1], jmp[i + (1 << (k-1))][k - 1]);
            }
        }
    }

    int calc(int l , int r) {
        int k = log2(r - l + 1);
        // cerr << l << ' ' << r << ' ' << k << ' ' << jmp[l][k] <<  '\n';
        return min(jmp[l][k],jmp[r - (1 << k)+1][k]);
    }

};

void solve() {
    int n , q; cin >> n >> q;
    vector<int> a(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i];
    }
    RMQ rmq(n);
    rmq.init(a);
    while (q--) {
        int l , r; cin >> l >> r;
        cout << rmq.calc(l , r - 1) << '\n';
    }
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
