#include <iostream>
#include <algorithm>

using namespace std;

#define boost ios::sync_with_stdio(0);

int main() {
	boost;
	int n , k ;
	cin >> n >> k;

	if (k == 1 && n % 2 == 0) cout << "Huy";
	else if (k == 1 && n % 2 != 0) cout << "Khoi";
	else if (n == 0) cout << "Huy"; 
	else cout << "Khoi";

	return 0;
}