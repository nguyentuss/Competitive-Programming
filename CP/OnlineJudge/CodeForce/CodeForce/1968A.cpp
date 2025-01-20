//source:: 
#include <bits/stdc++.h>

using namespace std;

#define int long long

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e18 + 7;

void solve() {
    int x; cin >> x; 
    int mx = 0;
    int y = 0;
    for (int i = 1 ; i < x ; i++) {
        if (__gcd(i , x) + i > mx) {
            mx = __gcd(i , x) + i; 
            y = i;
        }
    }
    cout << y << '\n';
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