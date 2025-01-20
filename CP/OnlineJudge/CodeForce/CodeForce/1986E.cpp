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

void solve() {
    int n , k; cin >> n >> k;
    vector<int> a(n);
    for (int &u : a) cin >> u;
    map<int , vector<int>> mp; 
    for (int u : a) 
        mp[u % k].push_back(u); 
    int ans = 0;
    int odd = 0;
    for (auto [key , v] : mp) {
        sort(v.begin() , v.end());
        for (int x : v) cerr << x << " ";
        cerr << '\n';
        if (sz(v) % 2 == 0) {
            for (int i = 0 ; i < sz(v) ; i += 2) {
                ans = ans + (v[i + 1] - v[i])/k; 
            }
        }
        else {
            odd ++; 
            if (odd > 1) {
                cout << -1 << '\n';
                return;
            }
            int tmp = 0;
            for (int i = 1 ; i < sz(v) ; i += 2) {
                tmp = tmp + (v[i + 1] - v[i])/k;
            }
            int mn = tmp;
            for (int i = 1 ; i < sz(v) ; i += 2) {
                tmp = tmp - (v[i + 1] - v[i])/k;
                tmp = tmp + (v[i] - v[i - 1])/k;
                mn = min(mn , tmp); 
            }
            ans = ans + mn;
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