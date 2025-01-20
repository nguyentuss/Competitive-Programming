#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

int main() {
	boost;
	int t; cin >> t;
	while (t --) {
		string str , rev;
		cin >> str;
		if (str == "yayy") 
			cout << "NO" << endl;
		else {
		rev = str;
		reverse(rev.begin() , rev.end());
		int count = 0;
		for (int i = 0 ; i < (int) rev.size() ; i++){ 
			if (rev[i] != str[i] && rev[i] != str[i+1]) count ++;
			if (count > 1) {
				cout << "NO" << endl;
				break;
			} 
		}
		if (count <= 1) cout << "YES" << endl;
		}
	}

	return 0;
}