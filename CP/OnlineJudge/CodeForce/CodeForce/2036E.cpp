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
typedef pair<char, int> pii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
const int inf = 1e9;

void solve() {
    int n , k , q; cin >> n >> k >> q; 
    vector<vector<int>> a(n , vector<int>(k));
    for (int i = 0 ; i < n ;i ++) {
        for (int j = 0 ; j < k ; j++) {
            cin >> a[i][j];
        }
    }

    for (int j = 0 ; j < k ; j++) {
        int x = a[0][j];
        for (int i = 0 ; i < n ;i ++) {
            a[i][j] |= x; 
            x |= a[i][j];
        }
    }
    // for (int i = 0 ; i < n ; i++) {
    //     for (int j = 0 ; j < k ; j++) {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    while (q--) {
        int m ; cin >> m;
        int x; 
        char sign; 
        int val; 
        map<int , vector<pii>> mp;
        for (int i = 0 ; i < m ; i++) {
            int x; 
            char sign; 
            int val; 
            cin >> x >> sign >> val; 
            x--;
            mp[x].push_back(pii(sign , val));
        }   
        int vl = sz(mp);
        vector<vector<tuple<int , char , int>>> b(vl);
        int idx = 0;
        for (auto [x , y] : mp) {
            for (int i = 0 ; i < sz(y) ; i++) {
                b[idx].push_back({x , y[i].first , y[i].second});
            }
            idx++;
        }
        int left = 0 , right = n - 1;
        bool ok = true;
        for (int i = 0 ; i < vl ; i++) {
            for (auto [x, sign , val] : b[i]) {
                if (sign == '>') {
                    int l = left , r = right;
                    bool flag = false;
                    while (l <= r) {
                        int mid = (l + r) >> 1; 
                        if (a[mid][x] > val) {
                            flag = true;
                            r = mid - 1;
                        }
                        else {
                            l = mid + 1;
                        }
                    }
                    if (!flag) ok = false;
                    else left = l;
                }
                else {
                    bool flag = false;
                    int l = left , r = right;
                    while (l <= r) {
                        int mid = (l + r) >> 1; 
                        if (a[mid][x] < val) {
                            flag = true;
                            l = mid + 1;
                        }
                        else r = mid - 1;
                    }
                    if (!flag) ok = false;
                    else right = r;
                }
            }
            //cerr << left << " " << right << '\n';
        }
        if (!ok) cout << -1 << '\n';
        else cout << left + 1 << '\n';
    }
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