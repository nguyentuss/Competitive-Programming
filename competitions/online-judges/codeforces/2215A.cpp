#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
typedef pair<int, int> ii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int N = 1e5 + 7;
const int inf = 1e18;

void solve() {
    int n, k, p, q; cin >> n >> k >> p >> q;
    vector<int> f(n+1), f_1(n+1), f_2(n+1), f_3(n+1), a(n+1);
    for (int i = 1 ; i <= n ;i ++) { 
        cin >> a[i];
    }
    for (int i = 1 ; i <= n ; i++) {
        int a_1 = (a[i] % p);
        int a_2 = (a[i] % q) % p;
        f_1[i] = f_1[i - 1] + a_1;
        f_2[i] = f_2[i - 1] + a_2; 
        f_3[i] = f_3[i - 1] + min(a_1, a_2);
    }
    int ans = inf;
    for (int i = k ; i <= n ; i++) {
        ans =  min(ans, min(f_1[i] - f_1[i - k], f_2[i] - f_2[i - k]) + f_3[i-k] + f_3[n] - f_3[i]);
        // ans = min(ans, f[i]);
    }
    cout << ans << '\n';

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
