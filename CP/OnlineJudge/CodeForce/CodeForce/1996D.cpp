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
    int n , x; cin >> n >> x;
    int ans = 0;
    for (int a = 1 ; a <= n ;a ++) {
        for (int b = 1 ; b <= n ; b++) {
            if (a * b > n) break;
            int x1 = x - a - b; 
            int n1 = (n - a*b)/(a+b);
            if (x1 > 0 && n1 > 0) {
                ans = ans + min(x1 , n1);
            }
        }
    }
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