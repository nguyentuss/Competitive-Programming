#include <bits/stdc++.h>
 
using namespace std;
 
string s;
 
int main() {
      ios_base::sync_with_stdio(0); cin.tie(NULL);
      cout.tie(NULL);
      //freopen("PTIT123J.inp","r",stdin);
      //freopen("PTIT123J.out","w",stdout);
      while (getline(cin , s)) {
            if (s == ".") break;
            stack<char> mystack;
            bool found = true;
            for (auto x : s) {
                  if (x == '(') mystack.push('(');
                  else if (x == '[') mystack.push('[');
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
                              break;
                        }
                        else mystack.pop();
                  }
            }
            if (!found || mystack.size()) cout << "no" << '\n';
            else cout << "yes" << '\n';
      }
      return 0;
} 