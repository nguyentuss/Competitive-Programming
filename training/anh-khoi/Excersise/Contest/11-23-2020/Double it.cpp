#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

int main() {
	boost;
	int n , x; cin >> n;
	string st ="";

	while (n > 0) {
		if (n % 2 == 0) {
			x = (n - 2) / 2;
			st += 'B';
		}
		else {
			x = (n - 1)/2;
			st += 'A';
		}
		n = x;
	}
	reverse(st.begin(),st.end());
	cout << st;
	return 0;
}