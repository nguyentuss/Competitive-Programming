#include <bits/stdc++.h>

using namespace std;


int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	int t; cin >> t;
	while (t--) {
		long long n; cin >> n;
		if (n % 2 == 1) cout << "YES" << '\n';
		else {
			while (n != 1) {
				if (n % 2 == 1) break;
				n /= 2;
			}
			if (n % 2 == 1 && n != 1) cout << "YES" << '\n';
			else cout << "NO" << '\n'; 
		}
	}

	return 0;
}