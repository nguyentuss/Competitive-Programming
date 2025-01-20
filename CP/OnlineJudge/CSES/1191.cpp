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
const int N = 4e5 + 7;
const int MOD = 1e18 + 7;
const int H = 20;

int a[N];
int f[N];
int P[N][20];

void solve() {
    int n, k; cin >> n >> k;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        a[i + n] = a[i]; 
    }
    int m = 2 * n; 
    for (int i = 1 ; i <= m ; i++) {
        f[i] = f[i - 1] + a[i];
        //cerr << f[i] << " ";
    }
    //cerr << '\n';
    memset(P , -1 , sizeof(P));
    for (int i = m ; i >= 1 ; i --) {
        P[i][0] = upper_bound(f + 1  , f + 1 + m , f[i - 1] + k) - f;
    }
    for (int j = 1 ; j < 20 ; j++) {
        for (int i = 1 ; i <= m ; i++) {
            if (P[i][j - 1] != -1) {
                P[i][j] = P[P[i][j - 1]][j - 1];
            }
        }
    }
    int ans = inf; 
    for (int i = 1 ; i <= n ; i++) {
        int j = i, tm = 1;
        for (int h = H - 1 ; h >= 0 ; h--) {
            if (P[j][h] != -1 && P[j][h] < i + n) {
                j = P[j][h];
                tm += (1 << h);
            }
        }
        // cout << tm << " ";
        // cout << '\n';
        ans = min(ans , tm);
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