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
int test; 
bool status = false;
int idx = 0;
void solve() {
    int k; cin >> k;
    if (test == 10000 && k == 9) status = true;
    idx++;
    vector<int> g;
    for (int i = 0 ; i < k ; i++) {
        int n; cin >> n;
        for (int j = 0 ; j < n - 1 ; j++) {
            int x; cin >> x;
        }
        g.push_back(n);
    }
    sort(g.begin() , g.end() , greater<int>());
    int ans = g[0];
    //cout << mask << '\n';
    for (int i = 1 ; i < k ; i++) {
        int tmp = ans;
        for (int x = g[i] ; x > 0 ; x -= (1 << (__builtin_ctz(x)))) {
            ans = max(ans , tmp | x); 
            ans = max(ans , tmp | (x - 1));
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    test = 1;
    cin >> test;
    while (test--) {
        solve();
    }

} 