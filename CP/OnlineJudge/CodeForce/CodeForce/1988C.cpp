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
    int n; cin >> n;
    if (n == 1) {
        cout << 1 << '\n';
        cout << 1 << '\n';
        return;
    }
    int mm = 1;
    while (true) {
        if (mm > n) break;
        if (mm == n) {
            cout << 1 << '\n';
            cout << mm << '\n';
            return; 
        }
        mm *= 2;
    }
    vi v;
    int last = 0;
    int mul = 1;
    v.push_back(n);
    int cur = n;
    while (n > 0) {
        if (mul > n) break;
        int c = n & mul;
        if (c == mul) {
            int tmp = n - mul;
            v.push_back(tmp + last);
            n = tmp + last;
            last = mul;
        }
        mul *= 2;
    }
    reverse(v.begin() , v.end()); 
    cout << sz(v) << '\n';
    for (int x : v) cout << x << " ";
    cout << '\n';
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