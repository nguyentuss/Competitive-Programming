#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

string s;
int ans = 0;
bool check;

int main() {
	int n; cin >> n;
	for (int i = 0 ; i < n; i++) {
		check = true;
		cin >> s;
		if (s == "CHAMPAGNE" || s == "ABSINTH" || s == "TEQUILA" || s == "VODKA" || s == "WHISKEY" || s == "WINE" || s == "BEER" || s == "BRANDY" || s == "GIN" || s == "RUM" || s == "SAKE" ) {
			ans ++;
			check = false;
		}
		char c[1024];
		strncpy(c, s.c_str(), sizeof(c));
		c[sizeof(c) - 1] = 0;
		int a = atoi(c);
		if (a < 18 && a > 0 && check == true) ans ++;
	}
	cout << ans;

	return 0;
}