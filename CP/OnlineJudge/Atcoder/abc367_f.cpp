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
const int mod = 1e9 + 7;
const int N = 2e5 + 7;
const int base = 200003; 

int a[N] , b[N];
int fa[N] , fb[N];
int pw[N];

void solve() {
    int n , q; cin >> n >> q;
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    for (int i = 1 ; i <= n ; i++) cin >> b[i];
    pw[0] = 1;
    for (int i = 1 ; i <= n ; i++) pw[i] = (pw[i - 1] * base)%mod;
    for (int i = 1 ; i <= n ; i++) {
        fa[i] = (fa[i - 1] + pw[a[i]])%mod; 
        fb[i] = (fb[i - 1] + pw[b[i]])%mod;
    }
    while (q--) {
        int l , r, L , R; cin >> l >> r >> L >> R;
        if ((fa[r] - fa[l - 1] + mod)%mod == (fb[R] - fb[L - 1] + mod)%mod) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
    }

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