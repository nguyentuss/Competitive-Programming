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

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    int mx = 0;
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i];
        mx = max(mx , a[i]);
    }
    
    int idx = 0 , bx = 1; 
    while (bx <= mx) {
        idx ++;
        bx *= 2ll;
    }
    vector<int> g((1 << idx) + 7);
    vector<int> f((1 << idx) + 7);
    for (int i = 0 ; i < n ; i++) {
        g[a[i]] ++; 
        f[a[i]] ++;
    }
    rep(i , 0 , idx) {
        rep(mask , 0 , (1 << idx)) {
            if (mask & (1 << i)) {
                f[mask] += f[mask ^ (1 << i)]; 
            }
            if (!(mask & (1 << i))) {
                g[mask] += g[mask ^ (1 << i)];
            }
        }
    }
    for (int i = 0 ; i < n ; i++) {
        int c = ((1 << idx) - 1) ^ a[i];
        cout << f[a[i]] << " " << g[a[i]] << " " << n - f[c] << '\n';
    }
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