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
    int n , m; cin >> n >> m;
    int ans = 0;
    for (int i = 0 ; i < n ; i++) {
        int l; cin >> l;
        vector<int> a;
        for (int j = 0 ; j < l ; j++) {
            int x; cin >> x; 
            a.push_back(x);
        }
        sort(a.begin(),a.end()); 
        int mex = 0;
        for (int x : a) if (x == mex) mex++;
        a.push_back(mex);
        sort(a.begin() , a.end()); 
        mex = 0;
        for (int x : a) if (x == mex) mex++;
        ans = max(ans , mex);
    }
    //cout << ans << '\n';
    if (m <= ans) {
        cout << ans*(m + 1) << '\n';
    }
    else {
        cout << ans*(ans+1) + m*(m + 1)/2 - ans*(ans + 1)/2 << '\n';
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