//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define int long long	
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e18 + 7;

int f[20][20][20];
int to[20][20][20];

/**
 * Author: Noam527
 * Date: 2019-04-24
 * License: CC0
 * Source: folklore
 * Description:
 * Status: tested
 */

ll modpow(ll b, ll e) {
    ll ans = 1;
    for (; e; b = b * b, e /= 2)
        if (e & 1) ans = ans * b;
    return ans;
}

int solve_i(int n) {
    n /= 10;
    int cnt = 0;
    while (n % 10 == 9) {
        cnt++;
        n /= 10;
    }
    return cnt;
}

int maxdigital(int n) {
    int mx = 0;
    while (n) {
        mx = max(mx , n % 10); 
        n /= 10;
    }
    return mx;
}

void solve() {
    int n; cin >> n;
    for (int i = 0 ; i <= 18 ; i++) {
        for (int j = 0 ; j < 10 ; j++) {
            for (int k = 0 ; k < 10 ; k++) {
                if (i + j + k == 0) {
                    to[i][j][k] = 0;
                    continue;
                }
                if (i + k == 0) {
                    f[i][j][k] = 1; 
                    continue;
                }
                if (i == 0) {
                    if (j < k) f[i][j][k] = 1 , to[i][j][k] = (10 + j - k) % 10;
                    else f[i][j][k] = 2, to[i][j][k] = (10 - k) % 10;
                    continue;
                }
                int last = j;
                for (int num = 9 ; num >= 0 ; num --) {
                    f[i][j][k] += f[i - 1][last][max(num , k)]; 
                    last = to[i - 1][last][max(num , k)];
                }
                to[i][j][k] = last;
            }
        }
    }
    int ans = 0;
    while (n) {
        int i = solve_i(n);
        int j = n % 10;
        int k = maxdigital(n - n%modpow(10 , i + 1));
        ans += f[i][j][k]; 
        n -= modpow(10 , i + 1); 
        n = n - n % 10 + to[i][j][k];
    }
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test = 1; 
    //cin >> test; 
    while (test--) {
       solve();
    }
}