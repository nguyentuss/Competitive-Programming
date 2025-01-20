#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define fi freopen("PALIND.inp","r",stdin);
#define fo freopen("PALIND.out","w",stdout);

string s;

bool check(string t) {
	reverse(t.begin(),t.end());
	if (t == s) return true;
	return false;
}

int main() {
	boost;
	//fi;fo;

	cin >> s;

	if (check(s)) cout << "YES";
	else cout << "NO";

	return 0;
}