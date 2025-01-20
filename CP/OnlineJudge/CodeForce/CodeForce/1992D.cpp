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
    int k , n , m; cin >> n >> m >> k;
    queue<int> q; 
    string s; cin >> s;
    s = "L" + s;
    s += "L";
    vector<int> f(n + 3 , -1); 
    f[0] = k;
    for (int i = 0 ; i <= n ; i++) {
        if (f[i] == -1 || s[i] == 'C') continue;
        if (s[i] == 'L') {
            for (int j = 1 ; j <= m && i + j <= n + 1 ; j++) {
            if (s[i + j] == 'W') {
                f[i + j] = max(f[i + j] , f[i] - 1); 
            }
            else if (s[i + j] == 'L') {
                f[i + j] = max(f[i + j] , f[i]);
            }
            }
        }
        else if (s[i] == 'W') {
            if (s[i + 1] == 'W') {
                f[i + 1] = max(f[i + 1] , f[i] - 1);
            }
            if (s[i + 1] == 'L') {
                f[i + 1] = max(f[i + 1] , f[i]);
            }
        }
    }
    //for (int i = 0 ; i <= n + 1 ; i++) cout << f[i] << " ";
    if (f[n + 1] >= 0) cout << "YES\n"; 
    else cout << "NO\n";
    
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