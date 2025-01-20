#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

int main() {
	boost;
	long long a,b,n;
	cin >> a >> b >> n;
	//if (a < b) swap(a,b);
	bool check = false;
	long long gcd = __gcd(a,b);
	if (a % b != 0) cout << __gcd(a,b);
	else {
		long long count = 0;
		long long x = 1;
		while (b < a && x != a && n != 1) {
			x *= b;
			count ++;
			if (x == a) {
				check = true;
				break;
			}
			else if (x > a && x != a) {
				check = false;
				break;
			}
		}	
		cout << check;
		if (!check) cout << b;
		else {
			if (count < n) cout << a;
			else {
				while (count != n) {
					x *= b;
					count ++;
				}
				cout << x;
			}
		}	
	}


	return 0;
}