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
const int inf = 1e18;

void solve() {
    int n , W , H; cin >> n >> W >> H; 
    vector<int> w(n + 1) , c(n + 1);
    int maxval = 0;
    for (int i = 1 ; i <= n ; i++) {
        cin >> w[i] >> c[i];
        maxval += c[i];
    }
    vector<vi> dp(maxval + 1 , vi(2 , inf));
    vector<vi> newdp(maxval + 1 , vi(2 , inf));
    dp[0][0] = 0;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j <= maxval ; j++) {
            for (int stat = 0 ; stat < 2 ; stat++) {
                if (dp[j][stat] == inf) continue; 
                newdp[j][stat] = min(newdp[j][stat] , dp[j][stat]);
                if (dp[j][stat] + w[i + 1] <= W) {
                    newdp[j + c[i + 1]][stat] = min(newdp[j + c[i + 1]][stat], dp[j][stat] + w[i + 1]);
                }
                if (!stat) {
                    if (w[i + 1] <= H) {
                        newdp[j + c[i + 1]][stat^1] = min(newdp[j + c[i + 1]][stat^1], dp[j][stat]);
                    }
                }
            }
        }
        dp = newdp; 
        newdp.assign(maxval + 1 , vi(2 , inf));
    }
    int ans = 0;
    for (int i = 0 ; i <= maxval ; i++) {
        for (int stat = 0 ; stat < 2 ; stat++) {
            if (dp[i][stat] <= W) {
                ans = max(ans , i);
            }
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