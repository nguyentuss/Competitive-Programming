#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int a , b , c;
		cin >> a >> b >> c;
		int res = a + b + c;
		if (res > 2*a + 2 *b) res = 2*a + 2*b;
		if (res > 2*a + 2*c) res = 2*a + 2*c;
		if (res > 2*b + 2*c) res = 2*b + 2*c;
		cout << res << '\n';
	}
	return 0;
}