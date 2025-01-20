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
    int n , k; cin >> n >> k;
    vector<int> a(n);
    map<int , int> mp;
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    vector<pair<int , int>> b;
    for (auto [u , v] : mp) {
        b.push_back(pii(u , v));
    }
    int ans = b[0].second;
    int mx = b[0].second;
    int cur_sz = 1;
    int l = 0;
    for (int i = 1 ; i < sz(b) ; i++) {
        if (b[i].first == b[i-1].first + 1) {
            cur_sz++;
            while (cur_sz > k) {
                mx -= b[l].second; 
                cur_sz--;
                l++;
            }
            mx += b[i].second;
        }
        else {
            l = i;
            cur_sz = 1; 
            mx = b[i].second;
        }
        //cout << b[i].first << " " << mx << " " << cur_sz << " " << b[l].first << '\n';
        ans = max(ans , mx);
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