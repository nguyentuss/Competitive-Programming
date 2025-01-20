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
    vector<pair<int, int>> s; 
    for (int i = 0 ; i < n ; i++) {
        int a , b; cin >> a >> b;
        int tmp = 0;
        while (!s.empty() && (a > 0)) {
            int u = s.back().first , v = s.back().second;
            if (v == b) {
                a += u - tmp;
                s.pop_back();
            }
            else if (a < u) break;
            else {
                tmp = u; 
                s.pop_back();
            }
        }
        s.push_back(pii(a , b)); 
        cout << s[0].first << " ";
    }
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
    return 0;
}