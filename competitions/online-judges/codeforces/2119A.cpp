#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	int a , b, x, y; cin >> a >> b >> x >> y;
	if (a & 1 && a - 1 == b) {
		cout << y << '\n';
		return;
	}
	if (a > b) {
		cout << -1 << '\n';
		return;
	}
	if (x < y) {
		cout << (b - a) * x << '\n'; 
		return; 
	}
	else {
		if (a & 1) {
			cout << (b-a+1)/2*x + (b-a)/2*y << '\n';
		}
		else {
			cout << (b-a)/2*x + (b-a+1)/2*y << '\n';
		}
	}
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
