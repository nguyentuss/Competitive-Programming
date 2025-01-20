#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define fi freopen("ezgcd.inp","r",stdin);
#define fo freopen("ezgcd.out","w",stdout);

int main() {
	boost;
	fi;fo;
	int n , x; cin >> n;
	cin >> x;
	int ans = x;
	for (int i = 0 ; i < n - 1; i ++) {
		cin >> x;
		ans = __gcd(ans , x);
	}

	cout << ans;

	return 0;
}