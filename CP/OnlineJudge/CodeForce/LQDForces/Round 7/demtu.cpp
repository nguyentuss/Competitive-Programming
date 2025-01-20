#include <iostream>
#include <algorithm>
#include <string>
#include <limits.h>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

int main(){
	boost;

	int t; cin >> t; 
	while (t --){
		string str;
		int count[60] = {0};
		cin >> str;
		for (int i = 0 ; i < (int) str.size() ; i++) 
			count[(int) str[i] - 'a'] ++;
		int maximum = INT_MIN;
		char ans;
		for(int i = 0 ; i <= 59 ; i++) 
			if (maximum < count[i]) {
				maximum = count[i];
				ans = (char) ((int) i + 'a');
			}
		cout << ans << endl;
	}

	return 0;
}