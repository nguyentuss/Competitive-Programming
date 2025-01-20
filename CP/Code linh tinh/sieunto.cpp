#include <iostream>

using namespace std;


int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);

	freopen("sieunto.inp","r",stdin);
	freopen("sieunto.out","w",stdout);
	bool k = true;
	long long t , a; cin >> t;
	while (t --){
		k = true;
		cin >> a;
		if (a < 2) k = false;
		while (a) {
			for (int i = 2 ; i * i <= a ; i++) 
				if (a % i == 0) {
					k = false;
					break;
				}
			a /= 10;
		}
		cout << (k ? 1 : 0);
	}
	return 0;
}