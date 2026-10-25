#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("ngoac.inp","r",stdin);
	freopen("ngoac.out","w",stdout);
	string s; getline(cin , s);
	stack<string> mystack;
	vector<string> res;
	int cntOpen = 0 , cntClose = 0;
	for (auto x : s) {
		string a; 
		a = x;
		mystack.push(a);
		if (x == '(') cntOpen ++;
		if (mystack.top() == ")") {
			string tmp;	
			cntClose++;
			bool found = false;
			while (mystack.empty() == false) {
				tmp += mystack.top();
				if (mystack.top() == "(") {
					found = true;
					break;
				}
				mystack.pop();
			}
			if (found) {
				if (mystack.size() && mystack.top() == "(") mystack.pop();
				mystack.push(tmp);
				reverse(tmp.begin() , tmp.end());		
				res.push_back(tmp);
			}
			else {
				cout << -1;
				return 0;
			}
		}
	}
	if (cntOpen != cntClose) {
		cout << -1;
		return 0;
	}
	cout << res.size() << '\n';
	for (auto i : res) cout << i << '\n';
	return 0;
}