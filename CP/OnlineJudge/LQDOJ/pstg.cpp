#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define ll long long

ll n;

bool checkprime(ll x) {
	if (x <= 1) return false;
	if (x <= 3) return true;
	if (x % 2 == 0 || x % 3 == 0) return false;
	for (ll i = 5 ; i * i <= x ; i += 6) 
		if (x % i == 0 || (x % (i + 2) == 0)) return false;
	return true;
}	


ll euler(ll x) {

	ll ans = x;
	bool check = false;
	for (ll i = 2 ; i * i <= x ; i++) {
		check = false;
		if (x % i == 0) {	
			while (x % i == 0) {
				x /= i;
				check = true;
			}
			if (check) ans -= ans/i;
		}	
	}
	if (x > 1) ans -= ans / x;
	return ans;
}

int main() {
	boost;
	cin >> n;

	if (checkprime(n) == true) cout << n - 1;
	else cout << euler(n);

	return 0;
}