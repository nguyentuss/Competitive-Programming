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
    int n , q; cin >> n >> q;
    vector<char> c; 
    c.push_back('B'); 
    c.push_back('G');
    c.push_back('R');
    c.push_back('Y');
    map<string , set<int>> mp;
    vector<string> a;
    for (int i = 0 ; i < n ; i++) {
        string s; cin >> s;
        mp[s].insert(i);
        a.push_back(s);
    }
    auto check = [&](int x , int y) -> void {
        int ans = inf;
        for (auto u : a[x]) {
            string st = "";
            st += u;
            for (auto v : c) {
                if (u == v) continue;
                string vc = st; 
                vc = vc + v;
                sort(all(vc)); 
                if (vc == a[x]) continue;
                int xx = x; 
                int yy = y;
                if (xx > yy) swap(xx , yy);
                auto it = mp[vc].lower_bound(xx);
                if (it == mp[vc].end()) {
                    if (sz(mp[vc]) > 0) {
                        it--; 
                        ans = min(ans , abs(*it - x) + abs(*it - y));
                        //cout << abs(*it - x) + abs(*it - y) << '\n';
                    }
                }
                else {
                    if (xx <= *it && *it <= yy) {
                        cout << abs(x - y) << '\n';
                        return;
                    }
                    else {
                        ans = min(ans , abs(*it - x) + abs(*it - y));
                        if (sz(mp[vc]) > 1 && it != mp[vc].begin()) {
                            it--; 
                            ans = min(ans , abs(*it - x) + abs(*it - y));
                        }
                    }
                }
            }
        }
        if (ans != inf) {
            cout << ans << '\n';
        }
        else {
            cout << -1 << '\n';
        }
        return;
    };
    while (q--) {
        int x , y; cin >> x >> y;
        x--; y--; 
        if (a[x] == a[y] || a[x][0] == a[y][0] || a[x][0] == a[y][1] || a[x][1] == a[y][0] || a[x][1] == a[y][1]) {
            cout << abs(x - y) << '\n';
        }
        else {
            check(x , y);
        }
    }
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