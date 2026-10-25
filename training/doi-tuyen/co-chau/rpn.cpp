#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	string str; cin >> str;
	stack<int> s;
	for (int i = 0 ; i < str.size() ; i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			s.push(str[i] - '0');
		}
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
			int a = s.top();
			s.pop();
			int b = s.top();
			s.pop();
			if (str[i] == '+') s.push(b+a);
			else if (str[i] == '-') s.push(b-a);
			else if (str[i] == '*') s.push(b*a);
			else if (str[i] == '/') s.push(b/a);
		}
	}
	cout << s.top();

	return 0;
}