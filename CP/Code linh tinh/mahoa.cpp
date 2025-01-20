#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

#define boost ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

string s;

bool check(int x) {
	for (int i = 2 ; i <= (int) sqrt(x) ; i++) 
		if (x % i == 0) return false;
	return true;
}

int main() {
	boost;
	cin >> s;
	if (check((int) s.size()))
		for (int i = 0 ; i < (int) s.size() ; i++) cout << s[i];
	else {
		int x = (int) sqrt(s.size());
		while (x * ((int) s.size() / x) != (int) s.size()) 
			x --;
		for (int i = 0 ; i < (int) sqrt(s.size()) ; i++) 
			for (int j = i ; j < (int) s.size() ; j+=x)
				cout << s[j];
	}


	return 0;
}