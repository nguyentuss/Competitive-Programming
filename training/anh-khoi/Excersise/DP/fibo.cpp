#include <iostream>

using namespace std;


unsigned long long divide(unsigned long long x) {
	if (x == 0 || x == 1) 
		return 1;
	return divide(x - 1) + divide(x - 2);
	return 0;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	unsigned long long n ; cin >>n;

	cout << divide(n);

	return 0;
}