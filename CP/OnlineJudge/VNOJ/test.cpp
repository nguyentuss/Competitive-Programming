//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
 
int gt[1000001], MOD;
 
int fpow(int a, int n) {
    int tmp = 1;
    while (n) {
        if (n & 1) {
            tmp = (tmp * a) % MOD;
        }
        a = (a * a) % MOD;
        n >>= 1;
    }
    return tmp;
}
 
int c(int k, int n) {
    int ret = gt[n];
    // ret = (ret * fpow(gt[k], MOD-2)) % MOD;
    // ret = (ret * fpow(gt[n-k], MOD-2)) % MOD;
    ret = (ret / (gt[k])) % MOD;
    ret = (ret / (gt[n-k])) % MOD;
    return ret;
}


void solve() {
    int n;

    cin >> n >> MOD;

    gt[0] = 1;
    for (int i = 1 ; i <= 1000000 ; i++) {
        gt[i] = (gt[i-1] * i) % MOD;
    }

    // cout << c(0, 2) << " c\n";

    int p2 = 1;

    int res = 0;

    for (int i = 0 ; i < n ; i++) {
        int d = p2; 
        d = (d * c(i, n-1)) % MOD;
        // cout << p2 << " " << c(i, n-1) << "\n";
        res = (res + d) % MOD;
        p2 = (p2 * 2) % MOD;
    }

    cout << res;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    int test = 1; 
    while (test--) {
       solve();
    }
}