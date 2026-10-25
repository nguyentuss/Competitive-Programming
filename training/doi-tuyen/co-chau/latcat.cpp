#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	getline(cin , s);
	int total = 0;
	for (int i = 0 ; i < s.size() ; i++) {
		if (s[i] >= '1' && s[i] <= '9') total = total + s[i] - '0';
	}
	cout << total;
	return 0;
}