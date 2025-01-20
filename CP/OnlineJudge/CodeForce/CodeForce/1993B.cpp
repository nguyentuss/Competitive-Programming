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
int a[N]; 

void solve() {
    int n; cin >> n;
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    int dem = 0, cnt = 0;
    int mx = -inf;
    for (int i = 1; i <= n ; i++) {
        if (a[i] % 2 == 1) {
            dem++; 
            mx = max(mx,a[i]);
        }
        else cnt++;
    }
    if (dem*cnt == 0) {
        cout << 0 << '\n';
        return;
    }
    int ans = 0;
    sort(a + 1 , a + 1 + n);
    int pos = n+1;
    for (int i = 1 ; i <= n ; i++) {
        if (!(a[i]%2))
        {
            if (mx > a[i]) mx += a[i], ans++;
            else {
                pos = i; break;
            }
        }
    }
    for (int i = n ; i >= pos ; i--) {
        if (a[i]%2 == 0)
        {
            if (mx > a[i]) mx += a[i], ans++;
            else ans += 2, mx += a[i];  
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