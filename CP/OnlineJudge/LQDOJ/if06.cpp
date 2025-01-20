#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

int main() {
	boost;
	int n; cin >> n;
	if ((int)sqrt(n)*sqrt(n) == n) cout << "YES";
	else cout << "NO";


	return 0;
}