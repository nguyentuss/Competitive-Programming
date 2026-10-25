#include <iostream>
#include <algorithm>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

int main() {
	boost;
	long long n , k ; cin >> n >> k;

	long long chan , le;

	chan = n / 2;
	le = n - chan;

	if (k <= le) cout << ((k*2) + 1) - 2;
	else cout << ((k - le)*2); 

	return 0;
}