#include <iostream>
#include <string>
#include <map>
#include <cstring>
#include <stack>
#include <vector>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

int t;

int main() {
	boost;
	cin >> t;
	for (int test = 0 ; test < t ; test ++) {
	stack <int> mystack;
	string s; cin >> s;
	int d = s.size();
	for (int i = 0 ; i < d ; i++) {
		if (s[i] == '(') mystack.push(0);
		else if (s[i] == 'C') mystack.push(12);
		else if (s[i] == 'O') mystack.push(16);
		else if (s[i] == 'H') mystack.push(1);
		else if (s[i] >= '0' && s[i] <= '9') {
			int a = mystack.top();
			mystack.pop();
			a *= (int) s[i] - '0';
			mystack.push(a);
		}
		else if (s[i] == ')') {
			int sum = 0;
			while (true) {
				int t = mystack.top();
				sum += t;
				mystack.pop();
				if (t == 0) break;
			}	
			mystack.push(sum);
		}
	}
	int ans = 0;
	while (!mystack.empty()){
		ans += mystack.top();
		mystack.pop();
	}
	cout << ans << endl;
	}
	return 0;
}