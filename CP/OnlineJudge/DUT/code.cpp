#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast")

long long a;


int main(){
	//ios::sync_with_stdio(0); cin.tie(NULL);
	stringstream ss;
	cin >> a;
	ss << hex << a;
	string res = ss.str();
	/*for (int i = 0 ; i < res.size() ; i++) {
		cout << res[i] << " ";
	}*/
	if (a < 0) {
		int count = 0;
		for (int i = 8 ; i < res.size() ; i++)  {
			char c = res[i];
			count ++;
			cout << (char) toupper(c);
			if (count % 4 == 0) cout << " ";
		}
	}
	else {
		int count = 0;
		for (int i = 0 ; i < (8 - res.size()) ; i++) {
			cout << 0;
			if ((i + 1)%4 == 0) cout << " ";
		}
		for (int i = 0 ; i < (int) res.size() ; i++) {
			char c = res[i];
			count ++;
			cout << (char) toupper(c);
			if ((count + (8 - res.size()))% 4 == 0) cout << " ";
		}
	}
	return 0;
}