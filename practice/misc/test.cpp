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
const int mod = 1000;

void solve() {
    // int n = 2023;
    int n; cin >> n;
    // 0 : red
    // 1 : blue
    vector<vector<int>> f(n + 1 , vector<int>((1 << 3) , 0));
    f[0][0] = 1;
    for (int i = 1 ; i <= n ; i++) {
        if (i & 1) {
            // Odd
            for (int mask = 0 ; mask < (1 << 3) ; mask++) {
                // cerr << mask << '\n';
                if (!(mask & 1) && !(mask & (1 << 2))) {
                    for (int nmask = 0 ; nmask < (1 << 3) ; nmask++) {
                        int tmp = nmask;
                        tmp <<= 1;
                        if (tmp & (1 << 3)) tmp ^= (1 << 3);
                        //cerr << mask << ' ' << tmp << ' ' << (mask & tmp) << '\n';
                        if ((mask & tmp) == tmp) {
                            (f[i][mask] += f[i-1][nmask])%=mod;
                            // cerr << mask << ' ' << nmask << ' ' << tmp << '\n';
                        }
                    }
                }
                for (int nmask = 0 ; nmask < (1 << 3); nmask++) {
                    int tmp = nmask;
                    tmp <<= 1;
                    if (tmp & (1 << 3)) tmp ^= (1 << 3);
                    if ((mask & tmp) == tmp) {
                        (f[i][mask] += f[i-1][nmask])%=mod;
                    }
                }
            }
        }
        else {
            // Even
            for (int mask = 0 ; mask < (1 << 3) ; mask++) {
                if ((mask & 1) && (mask & (1 << 2))) {
                    for (int nmask = 0 ; nmask < (1 << 3) ; nmask++) {
                        int tmp = nmask;
                        tmp <<= 1;
                        if (tmp & (1 << 3)) tmp ^= (1 << 3);
                        //cerr << mask << ' ' << tmp << ' ' << (mask & tmp) << '\n';
                        if ((mask & tmp) == tmp) {
                            (f[i][mask] += f[i-1][nmask])%=mod;
                            // cerr << mask << ' ' << nmask << ' ' << tmp << '\n';
                        }
                    }
                }
                for (int nmask = 0 ; nmask < (1 << 3); nmask++) {
                    int tmp = nmask;
                    tmp <<= 1;
                    if (tmp & (1 << 3)) tmp ^= (1 << 3);
                    if ((mask & tmp) == tmp) {
                        (f[i][mask] += f[i-1][nmask])%=mod;
                    }
                }
            }
        }
    }    
    int ans = 0;
    for (int mask = 0 ; mask < (1 << 3) ; mask++) {
        (ans += f[n][mask])%=mod;
    }
    cout << ans % mod;
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
