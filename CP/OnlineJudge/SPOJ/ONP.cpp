#include <iostream>
#include <stack>

using namespace std;

stack<char> q;
int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	int t; cin >> t;
	for (int test = 0 ; test < t ; test ++) {
		string S;
		cin >> S;
		while(!q.empty()) q.pop();
		for (int i = 0 ; i < (int) S.size() ; i++) {
			if (S[i] == '+' || S[i] == '-' || S[i] == '*' || S[i] == '^' || S[i] == '/') 
				q.push(S[i]);
			else if (S[i] != ')' && S[i] != '(') cout << S[i];
			else if (S[i] == ')') {
				cout << q.top();
				q.pop();
			}
		}
		cout << endl;
	}
	return 0;
}