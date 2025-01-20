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
    vector<int> a(n + 1) , f(n + 1) , sum(n + 1);
    f[0] = 0;
    for (int i = 1 ; i <= n ; i++) {  
        cin >> a[i]; 
    }
    reverse(a.begin() + 1 , a.end());
    for (int i = 1 ; i <= n ; i++) {
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 1 ; i <= n ; i++) {
        int l = 1 , r = i; 
        int pos = -1;
        while (l <= r) {
            int mid = (l + r)/2;
            if (sum[i] - sum[mid - 1] > x) {
                l = mid + 1;
                pos = mid;
            }
            else {
                r = mid - 1;
            }
        }
        if (pos != -1)
            f[i] = f[i] + f[pos - 1];
        f[i] = f[i] + (i - max(0ll, pos));
        //cerr << f[i] << " " << pos << '\n';
    }
    int ans = 0;
    for (int i = 1 ; i <= n ; i++) {
        //cerr << f[i] << " ";
        ans += f[i];
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