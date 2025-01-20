#include <iostream>
#include <string>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

string s;

int main() {
	boost;

	getline(cin , s);
	for (int i = 0; i < (int) s.size() ; i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
	}
	cout << s;

	return 0;
}

