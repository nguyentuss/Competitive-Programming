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
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
const int inf = 1e9;

void solve() {
    int n , k; cin >> n >> k;
    vector<pii> chord;
    vector<int> vis(2*n + 1);
    for (int i = 0 ; i < k ; i++) {
        int x , y; cin >> x >> y;
        if (x > y) swap(x , y);
        chord.push_back(pii(x , y));
        vis[x] = vis[y] = true;
    }
    vector<int> po;
    for (int i = 1 ; i <= 2*n ; i++) {
        if (!vis[i]) po.push_back(i);
    }
    int l = 0 , r = sz(po)/2;
    while (r < sz(po)) {
        chord.push_back(pii(po[l] , po[r]));
        l++;
        r++;    
    }   
    int ans = 0;
    for (int i = 0 ; i < sz(chord) ; i++) {
        // cout << chord[i].fi << " " << chord[i].se << '\n';
        for (int j = i - 1 ; j >= 0 ; j--) {
            bool ok = false;
            if (chord[j].fi > chord[i].fi && chord[j].fi < chord[i].se && chord[j].se > chord[i].se && chord[j].se <= 2*n) {
                ok = true;
            }
            if (chord[j].fi < chord[i].fi && chord[j].se > chord[i].fi && chord[j].se < chord[i].se) {
                ok = true;
            }
            if (ok) ans++;
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
