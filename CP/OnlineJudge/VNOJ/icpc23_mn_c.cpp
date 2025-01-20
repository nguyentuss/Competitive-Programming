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
    int n, k; cin >> n >> k;
    vector<tuple<int , int , int>> x0 , y0 , z0;
    map<int , int> cnt_x , cnt_y , cnt_z;
    while (k--) {
        int x , y , z; cin >> x >> y >> z;
        if (x == 0) x0.push_back({x , y , z});
        if (y == 0) y0.push_back({x , y , z});
        if (z == 0) z0.push_back({x , y , z}); 
    }
    int ans = 0;
    for (auto [x , y , z] : x0) {
        ans += n; 
        cnt_z[z]++;
        cnt_y[y]++;
    }
    map<pair<int , int> , int> cnt_xy;
    for (auto [x , y , z] : y0) {
        ans += n - cnt_z[z]; 
        cnt_x[x]++; 
        for (auto [x1 , y1 , z1] : x0) {
            if (z == z1) cnt_xy[pii(x , y1)]++;
        }
    }
    for (auto [x , y , z] : z0) {
        ans = ans + n - cnt_x[x] - cnt_y[y] + cnt_xy[pii(x , y)];
    }
    cout << ans;
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