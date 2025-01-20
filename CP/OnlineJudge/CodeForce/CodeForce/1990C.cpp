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
    vector<int> a(n + 2);
    int sum = 0 , ans = 0;
    for (int i = 1 ; i <= n ;i ++) cin >> a[i] , ans += a[i];
    a[n + 1] = n + 1;
    vector<pair<int , int>> v;
    for (int k = 1 ; k <= 20 ; k++) {
        vector<int> cnt(n + 1);
        int f = 0; 
        for (int i = 1 ; i <= n ; i++) { 
            cnt[a[i]]++;
            if (cnt[a[i]] >= 2) f = max(f , a[i]);
            a[i] = f;
            ans += a[i];
        }
        // for (int i = 1 ; i <= n ;i ++) {
        //     cerr << a[i] << " "; 
        // }
        // cerr << '\n';
        int dem = 0;
        bool ok = true;
        for (int i = 1 ; i <= n ; i++) {
            if (a[i] != a[i + 1]) {
                dem++;
                if (dem == 1 && i != n) ok = false;
                v.push_back(pii(a[i] , dem));
                dem = 0;
            }
            else dem ++;
        }
        if (ok) break;
        v.clear();
    }
    for (int i = 1 ; i <= n ; i++) {
        sum += a[i];
        ans -= a[i];
    }
    int times = 0;
    reverse(v.begin() , v.end()); 
    for (auto [x , y] : v) {
        //cerr << x << " " << y << '\n';
        int tm = y*(y + 1)/2;
        ans = ans + tm*x + y*(sum - y*x); 
        sum -= y*x;
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