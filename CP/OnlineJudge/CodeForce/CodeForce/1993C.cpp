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
const int N = 2e5 + 7;

int a[N];

void solve() {
    int n , k; cin >> n >> k;
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    sort(a + 1,a + n + 1);
    for (int i = 1 ; i < n ; i++) {
        if (a[n] <= a[i]) continue;
        int gg = (a[n] - a[i])/k;
        gg = gg - gg%2; 
        a[i] = a[i] + k*gg;
        while (a[i] + k < a[n] + 1 && a[n] > a[i]) {
            a[i] += 2*k;
        }    
    }
    sort(a + 1,a + n + 1);
    bool ok = true;
    for (int i = 1 ; i < n ; i++) {
        if (a[i] + k >= a[n] + 1) continue;
        ok = false;
    }
    if (!ok) cout << "-1\n";
    else cout << a[n] << '\n';
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