//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define le(x) (x << 1ll)
#define ri(x) ((x << 1ll) + 1)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
const int inf = 1e9;

void solve() {
    int n; cin >> n;
    string a; cin >> a;
    string b; cin >> b;
    if (a == b) {
        cout << 0 << '\n';
        return;
    }
    int n1 , n2 , n3 , n4 , l1 , l2;
    n1 = n2 = n3 = n4 = l1 = l2 = 0; 
    for (int i = 0 ; i < n ; i++) {
        if (a[i] == b[i]) {
            l1++; 
            if (a[i] == '1') n1++; 
            else n2++;
        }
        else {
            l2++; 
            if (a[i] == '1') n3++;
            else n4++;
        }
    }
    int ans = inf; 
    if ((l1 & 1) && n1 == n2 + 1) ans = min(ans , l1); 
    if (!(l2 & 1) && n3 == n4) ans = min(ans , l2); 
    cout << (ans == inf ? -1 : ans) << '\n';

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