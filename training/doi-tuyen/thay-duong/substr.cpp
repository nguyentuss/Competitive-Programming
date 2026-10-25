#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define fi freopen("substr.inp","r",stdin);
#define fo freopen("substr.out","w",stdout);

int main(){
	boost;
	//fi;fo;

	string s; cin >> s;
	int l = 0 ;
	int maximum = -1, maximums = -1;
	for (int i = 0 ; i < (int) s.size() ; i++) {
		int count[257] = {0};
		l = 0;
		for (int j = i ; j < (int) s.size() - 1; j++) {
			count[(int) s[j]] ++;
			if (count[(int) s[j]] > 1) 
				break;
			l ++;
			if (maximum < l) {
				maximum = l;
				//cout << maximum << endl;
				maximums = j;
			}

		}
	}
	cout << maximums << " " << maximum;

	return 0;
}