//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

void solve() {
    int n, x; cin >> n >> x;
    vector<int> a(n); 
    for (int i = 0 ; i < n ; i++) cin >> a[i]; 
    vector<int> f(x + 1 , 0);
    f[1] = 1;
    int ans = 0;
    vector<int> trace;
    for (int val : a) {
        if (val == 1 && val > x) continue;
        if (!(x % val)) {
            int c = x / val;
            vector<int> tmp;
            for (int i = 1 ; i * i <= c ; i ++) {
                if (c % i == 0) {
                    if (val * i <= x && !f[val * i] && f[i]) {
                        tmp.push_back(val * i);
                        trace.push_back(val * i);
                    }
                    if (c / i != i && c / i * val <= x && !f[c / i * val] && f[c / i]) {
                        tmp.push_back(c / i * val); 
                        trace.push_back(c / i * val);
                    }    
                }
            }
            for (int v : tmp) {
                f[v] = 1;
            }
        }
        if (f[x]) {
            ans ++; 
            for (int v : trace) f[v] = 0;
            trace.clear();
            f[val] = 1;
        }
    }
    ans++;
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test; 
    test = 1;
    cin >> test;
    while (test--) {
        solve();
    }

}