//source:: 
#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long
typedef unsigned __int128 ull;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 998244353;

int f[N][4][1 << 3];
int dp[N];
int a[N];

void solve() {
    int n; cin >> n;
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i];
    }
    f[0][0][0] = 1;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j <= 3 ; j++) {
            for (int mask = 0 ; mask < (1 << 3) ; mask++) {
                if (f[i][j][mask] == 0) continue;
                int cnt = __builtin_popcount(mask);
                if (cnt == 3) continue;
                // even => 000 , 2 bit avaiable
                if (j == 3) {
                    int cc = __builtin_popcount(mask);
                    if (cc == 0 || cc == 2) {
                        (f[i + 1][j][mask] += f[i][j][mask])%=MOD;
                    }
                }
                if (!(a[i] % 2)) {
                    if (j == 3) {
                        if (cnt == 0 || cnt == 2) {
                            int nmask = mask >> 1;
                            int cnt_1 = __builtin_popcount(nmask);
                            if (cnt_1 == 2 || cnt_1 == 0) {
                                (f[i + 1][j][nmask] += f[i][j][mask])%=MOD;
                            }
                        }
                    }
                    else {
                        (f[i + 1][j + 1][mask] += f[i][j][mask])%=MOD;
                        (f[i + 1][j][mask] += f[i][j][mask])%=MOD;
                    }
                }
                else {
                    if (j == 3) {
                        if (cnt == 0 || cnt == 2) {
                            int nmask = mask >> 1;
                            int cnt_1 = __builtin_popcount(nmask); 
                            if (cnt_1 == 1) {
                                (f[i + 1][j][nmask | (1 << 2)] += f[i][j][mask])%=MOD;
                            }
                        }
                    }
                    else {
                        (f[i + 1][j + 1][mask | (1 << j)] += f[i][j][mask])%=MOD;
                        (f[i + 1][j][mask] += f[i][j][mask])%=MOD;
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int mask = 0 ; mask < (1 << 3) ; mask++) {
        int cnt_1 = __builtin_popcount(mask);
        if (cnt_1 == 0 || cnt_1 == 2) {
            (ans += f[n][3][mask])%=MOD;
        }
    }
    cout << ans;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test = 1; 
    //cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}