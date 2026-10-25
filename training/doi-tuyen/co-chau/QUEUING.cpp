#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits.h>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define fi freopen("queuing.inp","r",stdin);
#define fo freopen("queuing.out","w",stdout);

string str;

int main(){
	boost;
	fi;fo;

	cin >> str;
	char s;
	for (int i = 0 ; i < (int) str.size() ; i++) 
		if (str[i] > str[i + 1]) {
			s = str[i];
			break;
		}

	for (int i = 0 ; i < (int) str.size() ; i++) {
		if (str[i] != s)
			cout << str[i];
	}



	return 0;
}