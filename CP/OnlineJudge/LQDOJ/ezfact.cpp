#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

int main(){
	boost;

	int t; cin >> t;

	map<unsigned long long , int> m;

	unsigned long long total = 1;
	for (int i = 1 ; i <= 20 ; i++) {
		total *= i;
		m[total] ++;
	}

	while (t --) {
		unsigned long long x; cin >> x;
		if (x == 0) cout << 1 << endl;
		else if (x == 1) cout << 2 << endl;
		else cout << m[x] << endl;
	}

	return 0;
}