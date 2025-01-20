#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> s;
	cout << (s[0] - '0') + (s[1] - '0') + (s[2] - '0');
	return 0;
}