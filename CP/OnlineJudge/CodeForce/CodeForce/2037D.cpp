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
    int n , m , L; cin >> n >> m >> L; 
    int pw = 1; 
    vector<tuple<int , int>> ed;
    for (int i = 0 ; i < n ; i++) {
        int l , r; cin >> l >> r; 
        ed.push_back({l , r});
    }
    vector<tuple<int , int>> b;
    for (int i = 0 ; i < m ; i++) {
        int x , v; cin >> x >> v;
        b.push_back({x , v});
    }
    int ans = 0;
    int p2 = 0;
    priority_queue<int> pq;
    int x = 0;    
    for (auto [l , r] : ed) {
        while (p2 < sz(b)) {
            auto [x , cnt] = b[p2];
            if (x >= l) break;
            p2++;
            pq.push(cnt);
        }
        if (x > r - l) {
            continue;
        }
        if (x <= r - l) {
            bool ok = false;
            while (!pq.empty()) {
                int u = pq.top(); 
                pq.pop(); 
                x += u; 
                ans++; 
                if (x > r - l) {
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                cout << -1 << '\n';
                return;
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
