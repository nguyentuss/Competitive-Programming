#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

int main() {
	boost;

	long long n , x , ans; cin >> n;
	for (int i = 0 ; i < n; i++) {
		cin >> x;
		if (i == 0) ans = x;
		else ans = __gcd(ans , x); 
	}

	if (ans == 1) cout << -1;
	else {
		for (int i = 2 ; i <= (int) ans / 2 ; i++) 
			if (ans % i == 0) {
				cout << i;
				return 0;
			}
		cout << ans;
	}

	return 0;
}