#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define fi freopen("timtu.inp","r",stdin);
#define fo freopen("timtu.out","w",stdout);

int main(){
	boost;
	fi;fo;

	string s , ans = "";
	while (cin >> s) {
		if (ans.size() < s.size()) ans = s;
	}
	cout << ans;

	return 0;
}