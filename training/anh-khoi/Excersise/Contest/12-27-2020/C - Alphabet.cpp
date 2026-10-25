#include <iostream>
#include <algorithm>
#include <cstring>
#include <limits.h>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

string s;
int ans = INT_MAX;

int main (){
	boost;

	cin >> s;

	int d = s.size();

	string num = "abcdefghijklmnopqrstuvwxyz";

	int k = 0;
	int left = 0;
	int length = 0;

	for (int i = 0 ; i < d ; i++){
		if (s[i] == num[k]){ 
			length = i - left + 1;
			ans = 26 - length;
		}
		else {
			cout << 26 - length;
			ans = min(ans ,26 - length);
			left = i;
		} 
		k ++;
	}
	cout << ans;

	return 0;
}