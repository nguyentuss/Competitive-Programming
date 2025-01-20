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
    vector<int> a(n);
    for (int &u : a) cin >> u;
    vector<vector<pii>> cnt(5E6 + 1);
    for (int i = 0 ; i < min(n , 4000ll) ; i++) {
        for (int j = i + 1 ; j < min(n , 4000ll) ; j++) {
            bool ok = 1;
            for (auto [x , y] : cnt[a[i] + a[j]]) {
                if (x == i || x == j || y == i || y == j) {
                    ok = 0;
                    break;
                }
            }
            if (ok) cnt[a[i] + a[j]].push_back({i , j});
            if (sz(cnt[a[i] + a[j]]) == 2) {
                cout << "YES\n"; 
                for (auto [x , y] : cnt[a[i] + a[j]]) {
                    cout << x + 1 << " " << y + 1 << " ";
                }
                return;
            }
        }
    }
    cout << "NO";
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test; 
    test = 1;
    while (test--) {
        solve();
    }

}