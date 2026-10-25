//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
typedef pair<int, int> ii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int inf = 1e18;

void solve() {
    int n; cin >> n;
    vi f(n + 1 , inf); 
    f[0] = 0; 
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j * j * j <= i ; j++) {
            if (f[i - j * j * j] != inf) {
                f[i] = min(f[i] , f[i - j * j * j] + 1);
            }
        }
    }
    cout << f[n];
}

main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
    int test = 1;
    while (test--) {
        solve();
    }
}