#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits.h>

using namespace std;

#define BOOST ios::sync_with_stdio(0); cin.tie(NULL);

long long n , x , a , ans = LLONG_MAX;

int main() {
	BOOST;
	cin >> n >> x;

	for (int i = 0 ; i < n ; i++) {
		cin >> a;
		if (a >= x) ans = min(ans , a);
		else {
			if (x % a != 0) ans = min(ans , a * ((x/a) + 1));
			else ans = min(ans , a * (x/a));
		}
	}
	
	if (x != 0) cout << ans;
	else cout << 0;

	return 0;
}