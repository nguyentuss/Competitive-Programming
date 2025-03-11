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
const int mod = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<vector<int>> f(n + 1 , vector<int>(1 << 2));
    f[0][3] = 1; 
    for (int i = 1 ; i <= n ; i++) {
        (f[i][1] = f[i - 1][3] + f[i - 1][2])%=mod;
        (f[i][2] = f[i - 1][3] + f[i - 1][1])%=mod;
        (f[i][3] = f[i - 1][3] + f[i - 1][2] + f[i - 1][1])%=mod;
    } 
    cout << (f[n][1] + f[n][2] + f[n][3])%mod;
}

signed main() {
    freopen("dplaga2.inp","r",stdin);
    freopen("dplaga2.out","w",stdout); 
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test; 
    test = 1;
    // cin >> test;
    while (test--) {
        solve();
    }
 
}
