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

int dis(int x1 , int y1 , int x2 , int y2) {
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

void solve() {
    int n; cin >> n;
    vector<pii> a(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i].first >> a[i].second;
    }
    int xs , ys , xt , yt; cin >> xs >> ys >> xt >> yt; 
    bool ok = true;
    for (int i = 0 ; i < n ;i ++) {
        if (dis(xs , ys , xt , yt) >= dis(xt , yt , a[i].first , a[i].second)) {
            ok = false;
            break;
        }
    }
    if (!ok) cout << "No\n";
    else cout << "Yes\n";
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