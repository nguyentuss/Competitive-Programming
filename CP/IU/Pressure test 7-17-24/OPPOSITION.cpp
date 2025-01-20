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
    int n, m; cin >> n >> m; 
    int left, right; cin >> left >> right;
    vector<pii> a , b;
    for (int i = 0 ; i < n ; i++) {
        int x , y; cin >> x >> y; 
        a.push_back(pii(x , y)); 
    }
    for (int i = 0 ; i < m ; i++) {
        int x , y; cin >> x >> y;
        b.push_back(pii(x , y));
    }
    sort(a.begin() , a.end()); 
    sort(b.begin() , b.end());
    int l = left - b[0].first;
    int r = right - b[m - 1].second;
    auto f = [&](int k) -> int {
        vector<pii> c(m); 
        for (int i = 0 ; i < m ; i++) {
            c[i] = pii(b[i].first + k , b[i].second + k);  
        }
        int ans = 0;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                if (a[i].first <= c[j].first) {
                    //cerr << a[i].first << " " << a[i].second << " " << c[j].first << " " << c[j].second << " ";
                    if (c[j].second <= a[i].second) {
                        ans = ans + (c[j].second - c[j].first);
                        //cerr << c[j].second - c[j].first << '\n';
                    }
                    else if (c[j].first < a[i].second) {
                        ans = ans + (a[i].second - c[j].first);
                        //cerr << a[i].second - c[j].first << '\n';
                    }
                }
            }
            //cout << ans << '\n';
        }
        return ans;
    };
    while (r - l > 1) {
        int mid = (l + r) >> 1; 
        cerr << mid << '\n';
        if (f(mid) > f(mid + 1)) {
            r = mid;
        }
        else {
            l = mid;
        }   
    }
    //for (int i = 0 ; i <= m ; i++) cout << f(i) << " ";
    cout << f(l);
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test; 
    test = 1;
    //cin >> test;
    while (test--) {
        solve();
    }

}