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
    vector<int> a(n + 1) , L(n + 1) , R(n + 1); 
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    stack<int> s; 
    for (int i = 1 ; i <= n ; i++) {
        while (!s.empty() && a[i] < a[s.top()]) {
            R[s.top()] = i - 1; 
            s.pop();
        }
        L[i] = (s.empty() ? 1 : s.top() + 1); 
        s.push(i);
    }
    while (!s.empty()) {
        R[s.top()] = n; 
        s.pop();
    }
    int ans = 0;
    for (int i = 1 ; i <= n ; i++) {
        ans = ans + (i - L[i] + 1) * (R[i] - i + 1) * a[i];
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test; 
    test = 1;
    //cin >> test;
    while (test--) {
        solve();
    }

}