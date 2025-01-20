#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <cstring>


using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

char s[1024]; 
int k;
set <char> m;

int main() {
	boost;
	cin >> s;
	for (int i = 0 ; i < (int) strlen(s) ; i++) 
		m.insert(s[i]);

	cin >> k;
	int d = m.size();
	if (k > (int) strlen(s)) cout << "impossible";
	else if (d > k) cout << 0;
	else cout << k - d;

	return 0;
}