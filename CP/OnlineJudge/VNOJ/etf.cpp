#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	int t ; cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int ans = n;
		for (int i = 2 ; i * i <= n ; i++) {
			if (n % i == 0) {
				while (n % i == 0) {
					n /= i;
				}
				ans -= ans/i;
			}
		}
		if (n != 1) {
			ans -= ans / n;
		}
		cout << ans << '\n';
	}

	return 0;
}