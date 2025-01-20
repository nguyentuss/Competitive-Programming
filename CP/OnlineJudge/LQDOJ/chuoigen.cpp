#include <iostream>
#include <string>
#include <limits.h>


using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

int main(){
	boost;
	int n; cin >> n;
	string s;
	cin >> s;

	int ans = INT_MAX , total = 0;

	for (int i = 0 ; i <= n - 4; i ++) {
		total = 0;
		total += (int) min(abs((int) s[i] - 'A'),((int) abs((int)s[i] - 91)));	
		total += (int) min(abs((int) s[i+1] - 'C'),((int) abs((int)s[i+1] - 93)));	 
		total += (int) min(abs((int) s[i+2] - 'T'),((int) abs((int)s[i+2] - 120)));	
		total += (int) min(abs((int) s[i+3] - 'G'),((int) abs((int)s[i+3] - 97)));	 
		ans = min(ans,total);
	}

	cout << ans;
	return 0;
}