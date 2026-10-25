#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (207)

char a[MAX_N];
int m;
int X[16];
int num[] = {1 , 0 , 1 , 2 , 3 , 4 , 5};
char ch[] = {'(' , '[' , '{' , '}' , ']' , ')'};
int ans = 0; 
int n;
bool check = true;
string s;
void calc() {
	/*int cnt = 1;
	for (int i = 1 ; i <= n ; i++) {
		if (a[i] == '?') {
			s += ch[num[X[cnt++]]];
		}
		else s += a[i];
	}*/
	cout << s << '\n';
	stack<char> mystack;
    bool found = true;
    for (auto x : s) { 
          if (x == '(') mystack.push('(');
          else if (x == '[') mystack.push('[');
          else if (x == '{') mystack.push('{');
          else if (x == ')') {
                if (mystack.empty() || mystack.top() != ('(')) {
                      found = false;
                      break;
                }
                else mystack.pop();
          }
          else if (x == ']') {
                if (mystack.empty() || mystack.top() != ('[')) {
                      found = false;
                      cout << "YES";
                      break;
                }
                else mystack.pop();
          }
          else if (x == '}') {
          		if (mystack.empty() || mystack.top() != ('{')) {
          			found = false;
          			break;
          		}
          }
    }
    if (!found || mystack.size()) ans += 0;
    else ans += 1;
}

void backtr(int i) {
	for (int j = 1 ; j <= 6 ; j++) {
		X[i] = j;
		if (i == m) calc();
		else backtr(i + 1);
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("test.inp","r",stdin);
	freopen("test.out","w",stdout);
	/*cin >> n;
	for (int i = 1 ; i <= n ; i++) {
		cin >> a[i];
		m += (a[i] == '?' ? 1 : 0);
	}
	backtr(1);*/
	s = "[{(())}]";
	calc();
	cout << ans;
	return 0;
}