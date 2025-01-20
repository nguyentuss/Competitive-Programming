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
    int n, k; cin >> n >> k;
    vector<int> a(n);
    vector<int> b(n);
    priority_queue<pii> pq;
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i]; 
    } 
    for (int i = 0 ; i < n ; i++) {
        cin >> b[i];
    }
    for (int i = 0 ; i < n ; i++) pq.push(pii(a[i] , b[i]));
    int ans = 0;

    while (!pq.empty()) {
        auto [a1 , b1] = pq.top();
        if (a1 <= 0) break;
        pq.pop();
        int k1 = (a1 - pq.top().first)/b1 + 1;
        //cerr << k1 << '\n';
        int m = min(k , k1);
        int tmp = m;
        ans = ans + m*a1 + m*(m - 1)/2*(-b1);
        a1 = a1 - tmp*b1;
        k = k - tmp;
        //cerr << a1 << " " << b1 << " " << ans << " " << k << '\n';
        if (!k) break;
        pq.push({max(0ll , a1) , b1});
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