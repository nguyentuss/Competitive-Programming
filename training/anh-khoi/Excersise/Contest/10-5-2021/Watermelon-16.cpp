#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	
	int n; cin >> n;
	for (int i = 1 ; i <= n ; i++) {
		int x; cin >> x;
		if (x == 2) {
			cout << "NO" << '\n';
			continue;
		}
		if (x % 2 == 0) {
			  cout << "YES" << '\n';

		}
		else cout << "NO" << '\n';
	}

	return 0;
}