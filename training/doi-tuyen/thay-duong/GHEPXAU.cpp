#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define fi freopen("ghepxau.inp","r",stdin);
#define fo freopen("ghepxau.out","w",stdout);

string s1 , s2;

int main(){
	boost;
	fi;fo;

	cin >> s1; 
	cin >> s2;

	string s; 
	int ans = 0;
	while ((int) s.size() <= s2.size()) {
		s += s1;
		ans ++;
		if (s == s2) {
			cout << ans;
			return 0;
		}
	}
	cout << 0;

	return 0;
}