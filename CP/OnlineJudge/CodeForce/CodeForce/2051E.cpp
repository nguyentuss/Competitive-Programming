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
    int n , k; cin >> n >> k;
    vi a(n);
    vi root;
    int cnt = 0;
    map<int , vector<int>> mp;
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i];
        cnt++;
        root.push_back(a[i]);
    }
    vi b(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> b[i]; 
        root.push_back(b[i]);
        mp[a[i]].push_back(b[i]); 
    }  
    sort(all(root));
    root.erase(unique(all(root)),root.end());
    int ans = 0;
    map<int , int> lmp;
    int cnt1 = 0;
    
    for (int i = 0 ; i < sz(root) ; i++) {
        if (cnt1 <= k)
        ans = max(ans , cnt * root[i] + root[i] * cnt1);
        // cout << root[i] << ' ' << cnt << ' ' << cnt1 << '\n';
        cnt -= sz(mp[root[i]]);
        for (int x : mp[root[i]]) {
            lmp[x] ++;
            cnt1++;
        }
        cnt1 -= lmp[root[i]];
        lmp.erase(root[i]);
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
