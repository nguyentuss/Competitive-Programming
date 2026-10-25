#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define fi freopen("richnum.inp","r",stdin);
#define fo freopen("richnum.out","w",stdout);

bool isprime(int x) {
	if (x <= 1) return false;
	if (x <= 3) return true;
	if (x % 2 == 0 || x % 3 == 0) return false;
	for (int i = 5 ; i * i<= x ; i += 6) 
		if ((x % i == 0)|| (x % (i + 2) == 0))
			return false;
	return true;
}

int main () {
	boost;
	fi;fo;
	int l , r; cin >> l >> r;

	int ans = 0;
	for (int i = l ; i <= r ; i++) {
		if (!isprime(i)) {
			long long total = 0;
			for (int j = 1 ; j <= (int) sqrt(i) ; j++) {
				if (i % j == 0) {
					if (j == (int) i / j)
						total += j;
					else {
						total += j + ((int) i / j);
					}
				}
			}
			total -= i;
			//cout << i << " " << total << endl;
			if (total > i) ans ++; 
		}
	}
	cout << ans;

	return 0;
}