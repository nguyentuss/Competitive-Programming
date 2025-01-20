//source:: https://codeforces.com/contest/1618/problem/D
#include <bits/stdc++.h>

using namespace std;

#define int long long

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e18 + 7;

void solve() {
    int n , k; cin >> n >> k;
    vector<int> a;
    for (int i = 0 ; i < n ; i++) {
        int x; cin >> x;
        a.push_back(x); 
    }
    int sum = 0;
    sort(a.begin()  , a.end());
    for (int i = 0; i < k; i++) {
			sum += a[n - i - k - 1] / a[n - i - 1];
		}
		for (int i = 0; i < n - 2 * k; i++) {
			sum += a[i];
		}
    cout << sum << '\n';
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); 
    cout.tie(NULL);
    int test = 1;
    cin >> test;
    while(test--) {
        solve();
    }
    return 0;
}