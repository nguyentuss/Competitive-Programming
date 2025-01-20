#include <string>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

string s;
long long count1 = 1 , counted , ans1 = 0 , ans2 = 0;

int main() {
	boost;

	int n; cin >> n;
	cin >> s;

	for (int i = 0 ; i < (int) s.size() ; i++)
		if (s[i] == 'u') count1 ++;
	counted = count1;
	for (int i = 0 ; i < (int) s.size() ; i++) {
		if (s[i] == 'u') counted --;
		else if (s[i] == 'c') ans1 += counted;
	}
	counted = count1 - 1;
	ans2 = counted;
	for (int i = 0 ; i < (int) s.size() ; i++) {
		if (s[i] == 'u') {
			counted --;
		}
		else if (s[i] == 'c') ans2 += counted;
	}
	//cout << ans1 << " " << ans2 << endl;
	cout << max(ans1,ans2);	

	return 0;
}