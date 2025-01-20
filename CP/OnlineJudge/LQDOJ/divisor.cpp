#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

int main() {
	boost;
	long long n , total = 0 , counted = 0; cin >> n;
	for (int i = 1 ; i <= (int) sqrt(n) ; i++) 
		if (n % i == 0) {
			if (i == ((int) n / i)) {
				total += i;
				counted ++;
			}
			else {
				total += i + (int) (n / i);
				counted += 2;
			}
		}

	cout << counted << " "  << total;	

	return 0;
}