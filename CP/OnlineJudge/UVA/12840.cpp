//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define le(x) (x << 1ll)
#define ri(x) ((x << 1ll) + 1)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
const int inf = 1e9;

void solve() {
    int n , S; cin >> n >> S;
    vi a(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i];
    }
    reverse(all(a));    
    vi b(n);
    vi c;
    int ans = inf;

    function<void(int , int , int)> backtrack = [&](int i , int cur_sum , int cnt) {
        int at_sum = 0;
        for (int j = 0 ; j <= 300 ; j++) {
            at_sum = j * a[i];
            if (cur_sum + at_sum > S || cnt + j > ans) return;
            b[i] = j;
            if (cur_sum + at_sum == S) {
                ans = cnt + j;
                c = b; 
                b[i] = 0;
                return;
            }
            if (i != n - 1) backtrack(i + 1 , cur_sum+at_sum, cnt + j);
            b[i] = 0;
        }
    };
    backtrack(0 , 0 , 0);
    if (ans == inf) {
        cout << "impossible\n";
    }
    else {
        cout << "[" << ans << "] ";
        int ic = 0;
        for (int i = 0 ; i < n ; i++) {
            if (c[i]) {
                for (int j = 0 ; j < c[i] ; j++) {
                    ic++;
                    cout << a[i];
                    if (ic!=ans) cout << " ";
                }
            }
        }
        cout << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test; 
    test = 1;
    cin >> test;
    int t = 0;
    while (test--) {
        cout << "Case " << ++t << ": ";
        solve();
    }
 
}
