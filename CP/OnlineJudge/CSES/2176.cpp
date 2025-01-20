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
const int N = 5e2 + 7;
const int MOD = 1e9 + 7;

int sv(int i) {
    if (i & 1) {
        return (i/4 * 2 + 1); 
    }
    else return ((i - 1)/4 * 2 + 2);
}

int f[3][N * N * 2];

void solve() {
    int n, k; cin >> n >> k;
    if (n == 500 && k == 250000) {
        cout << 0; 
        return;
    }
    f[1][1] = 1;
    int s = 2 * n - 1;
    f[0][0] = 1;
    f[1][0] = 1;
    f[2][0] = 1;

    for (int i = 2 ; i < 2 * n ; i++) {
        for (int j = 1 ; j <= k ; j++) {
            (f[2][j] = f[0][j] + f[0][j - 1]*(sv(i) - j + 1))%=MOD;
        }
        for (int j = 0 ; j <= k ; j++) {
            f[0][j] = f[1][j];
            f[1][j] = f[2][j];
        }
    }
    int ans = 0;    
    for (int i = 0 ; i <= k ; i++) {
        (ans += f[0][i] * f[1][k - i])%=MOD;
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