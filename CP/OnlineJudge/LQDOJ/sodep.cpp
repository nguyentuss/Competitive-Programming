#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

string s;

int main() {
	boost;

	cin >> s;

	long long ans = 0;

	for (int i = 0 ; i < (int) s.size(); i++) 
		ans += (int) s[i] - '0';
	while (ans > 9) {
		string s = to_string(ans);
		ans = 0;
		for (int i = 0 ; i < (int) s.size() ; i++) 
			ans += (int) s[i] - '0';
	}
	cout << ans;

	return 0;
}