#include <iostream>
#include <algorithm>
#include <string>
#include <cstring> 

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define oo (int) 1e-9

string s;
bool mycount[257];
int pos[257];
int ans = oo;

int main() {
	boost;
	cin >> s;

	int d = s.size();
	int left = 0 , posleft = 0;
	memset(mycount,false,sizeof(mycount));
	for (int i = 0 ; i < d; i++) {
		if (mycount[(int) s[i]] == false) {
			cout << i << " " << left << endl;
			pos[(int) s[i]] = i;
			mycount[(int) s[i]] = true;
			ans = max(ans,i - left + 1);
			//acout << ans << endl;
		}
		else {
			ans = max(ans,i - left);
			cout << "TRUE" << i << " " << left << endl;
			//for (int j = posleft ; j <= pos[(int) s[i]] ; j ++) mycount[(int) s[j]] = false;
			posleft = i;
			mycount[i] = true;
			left = pos[(int) s[i]] + 1;
			pos[(int) s[i]] = i;
		}
	}
	cout << ans;


	return 0;
}