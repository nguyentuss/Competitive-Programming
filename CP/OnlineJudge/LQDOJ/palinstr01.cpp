#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

int main(){
	boost;
	string str;
	while (cin >> str) {
		string rev = str;
		int k = 0;
		bool check = false;
		reverse(rev.begin() , rev.end());
		for (int i = 0 ; i < (int) rev.size() / 2; i++) {
			if (rev[i] != str[i]) k ++; 
			if (k > 2) {
				cout << "NO" << endl;
				check = true;
				break;
			}
		}
		if (!check) cout << "YES" << endl;
	}

	return 0;
}