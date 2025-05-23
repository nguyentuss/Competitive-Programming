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
    vector<int> a(n + 1); 
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
    }
    int sum = 0,maxx = 0;
	for(int i = 2 ; i <= n ;++i)
		if(a[i] < a[i - 1]) {
			sum += a[i - 1] - a[i];
			maxx = max(maxx,a[i - 1] - a[i]);
			a[i] = a[i - 1];
		}
	cout << sum + maxx << '\n';
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