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
const int inf = 1e9;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    vector<int> f(n + 1);
    for (int i = 1 ; i <= n ; i++) 
        f[i] = f[i - 1] + (a[i] ? 1 : 0);
    int left_most = (a[1] <= 2 ? 1 : 0);
    for (int i = 2 ; i <= n ;i ++) {
        f[i] = min(f[i] , f[i - 1] + 1);
        //cout << left_most << " ";
        if (a[i] == 0) {
            f[i] = f[i - 1];
            continue;
        }
        if (a[i] > 4) {
            left_most = 0;
            f[i] = min(f[i] , f[i - 1] + 1);
            continue;
        }   
        if (a[i] <= 2) {
            if (left_most && (i - left_most + 1) % 2 == 0) {
                //cerr << i << " " << left_most << '\n';
                f[i] = min(f[i] , f[left_most - 1] + (i - left_most));
            }
            left_most = i;
        }
    }
    // for (int i = 1 ; i <= n ; i++) {
    //    cerr << f[i] << " ";
    // }
    // cerr << '\n';
    cout << f[n] << '\n';
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