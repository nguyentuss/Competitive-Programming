//source:: 
#include <bits/stdc++.h>

using namespace std;

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e9 + 7;

#define int long long

// (x - y) + (x + y) - ((x - y) & (x + y))
// (x - y) => c - a[i] + 1
// (x + y) => x % 2 == 0 , x / 2 + 1 | x % 2 == 1 , x/2

void solve() {
    int n , c; cin >> n >> c;
    vector<int> a(n + 1);   
    int ans = (c + 1)*(c + 2)/2;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
    }
    int tmp = 0;
    for (int i = 1 ; i <= n ; i++) {
        tmp = tmp + (c - a[i] + 1);
        tmp = tmp + (a[i]/2) + 1; 
    }
    int even = 0 , odd = 0;
    for (int i = 1 ; i <= n ; i++) {
        if (a[i] % 2 == 0) even ++ , tmp -= even; 
        else odd ++ , tmp -= odd;
    }
    cout << ans - tmp << '\n';
    return; 
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