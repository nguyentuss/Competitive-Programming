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

int idx = 0;
 
void solve() {
    idx++;
    int n; cin >> n;
    double sum = 0;
    for (int i = 0 ; i < n + 1 ; i++) {
        int x; cin >> x;
        sum += x;
    } 
    double tmp = 0;
    for (int i = 0 ; i < n ; i++) {
        double a, b; cin >> a >> b;
        tmp = max(tmp , b);
    }   
    // cout << sum + tmp << '\n';
    cout << "Case #" << idx << ": ";
    cout << fixed << setprecision(10) << sum + tmp << '\n';
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