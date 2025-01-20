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

int sum(int x) {
    return x*(x + 1)/2;
}

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    int res = a * n;
    if (b > a) {
        int calc = sum(b) - sum(max(b - n, a)) + max(0ll, n - (b - a)) * a;
        res = max(res, calc);
    }
    cout << res << '\n';
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