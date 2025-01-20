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

void solve(){
    int n, m, k; cin >> n >> m >> k;
    vector v(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    vector<string> type(n);
    for(int i = 0; i < n; i++) cin >> type[i];
 
    vector pref(n + 1, vector<int>(m + 1));
    int diff = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + ((type[i - 1][j - 1] == '1') ? 1 : -1);
            diff += ((type[i - 1][j - 1] == '1') ? 1 : -1) * v[i - 1][j - 1];
        }
    }
    int g = 0;
    for(int i = 0; i + k <= n; i++) {
        for(int j = 0; j + k <= m; j++) {
            int val = pref[i + k][j + k] - pref[i + k][j] - pref[i][j + k] + pref[i][j];
            if(g == 0) g = val;
            else g = __gcd(g, val); 
        }
    }
    if(diff == 0 || (g != 0 && diff % g == 0)) cout << "YES" << '\n';
    else cout << "NO" << '\n';
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