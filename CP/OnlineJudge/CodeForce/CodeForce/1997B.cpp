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
const int N = 2e5 + 7;

int a[6][N];

void solve() {
    int n; cin >> n;
    for (int i = 1 ; i <= 2 ; i++) {
        for (int j = 1 ; j <= n ; j++) {
            char x; cin >> x;
           // cout << x;
            if (x == '.') a[i][j] = 0; 
            else a[i][j] = 1;
        }
    }
    int res = 0;
    // for (int i = 1 ; i <= 2 ;i ++) {
    //     for (int j = 1 ; j <= n ; j++) {
    //         cerr << a[i][j];
    //     }
    //     cerr << '\n';
    // }
    for (int i = 1 ; i <= n - 2 ; i ++) {
        if (!a[1][i] && !a[1][i + 1] && !a[1][i + 2] && a[2][i] && !a[2][i + 1] && a[2][i + 2]) {
            res++;
        }
        else if (!a[2][i] && !a[2][i + 1] && !a[2][i + 2] && a[1][i] && !a[1][i + 1] && a[1][i + 2]) {
            res++;
        }
    }
    cout << res << '\n';
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