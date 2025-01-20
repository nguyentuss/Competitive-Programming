#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
	int n; cin >> n;
	for (int i = 0 ; i < n ;i++) {
		string s;
		cin >> s;
		if (s == "0") cout << 0 << endl;
		else
		cout << s.size() << endl;
	}

	return 0;
}