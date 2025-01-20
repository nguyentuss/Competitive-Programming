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
    vector<int> a(n + 1) , f(n + 1);
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        f[i] = f[i - 1] + a[i];
    }
    vector<char> c(n + 1); 
    min_heap<int> pqL;
    priority_queue<int> pqR; 
    
    for (int i = 1 ; i <= n ; i++) {
        cin >> c[i];
        if (c[i] == 'L') pqL.push(i); 
        else pqR.push(i);
    }
    int ans = 0;
    while (!pqL.empty() && !pqR.empty()) {
        int u = pqL.top(); 
        int v = pqR.top(); 
        pqL.pop(); pqR.pop(); 
        if (u > v) break;
        ans = ans + f[v] - f[u - 1];
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