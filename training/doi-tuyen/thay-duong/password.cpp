#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <fstream>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define fi freopen("password.inp","r",stdin);
#define fo freopen("password.out","w",stdout);

string s;

bool checkprime(int x) {
	if (x <= 1) return false;
	if (x <= 3) return true;
	if (x % 2 == 0 || x % 3 == 0) return false;
	for (int i = 5 ; i * i <= x ; i += 6) 
		if (x % i == 0 || (x % (i + 2) == 0)) return false;
	return true;
}	


int main() {
	boost;
	fi;fo;

	cin >> s;
	s += "c";
	bool check = false;
	string str;
	unsigned long long ans = 0;
	string a;
	for (int i = 0 ; i < (int) s.size() ; i++) {
		if ((s[i] >= '0' && s[i] <= '9')) {
			str += s[i];
			check = true;
			//cout << str << endl;
		} 
		else if ((s[i] < '0' || s[i] > '9') && check) {
			for (int j = 0 ; j < (int) str.size() ; j++){
				a = "";	
				for (int k = j ; k < (int) str.size() ; k ++){
					a += str[k];
					//cout << a << endl;
					if (checkprime(atoi(a.c_str())) && atoi(a.c_str()) < 105){
						unsigned long long c = atoi(a.c_str());
						ans = max(ans , c);
					}  
				}
			}
			str = "";
			check = false;
		} 
		a = "";

	}
	cout << ans;

	return 0;
}