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
const int mod = 998244353;

void solve() {
   int n , m; cin >> n >> m;
   // in range 0->k*2^i there is k*2^(i-1) number contain j-th bit set
   int ans = 0;
   for (int i = 60 ; i >= 0 ; i--) {
        if (m & (1ll << i)) {
            int res = ((n>>(i+1))<<i)%mod;
            if (n&(1ll << i)) {
                (res += ((n&((1ll<<i)-1))+1)%mod)%=mod;
            }
            int c = ((n >> (i + 1)) << i);
            (ans += res)%=mod;
        }
   }
   cout << ans % mod << '\n';
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