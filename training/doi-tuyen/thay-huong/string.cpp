#include <iostream>
#include <string>

using namespace std; 

int main ()
{
  ios::sync_with_stdio(0); cin.tie(NULL);
  freopen("string.inp","r",stdin);
  freopen("string.out","w",stdout);

  string str,st;

  cin >> st ;

  for (auto it : st.begin()) 
  	str.push_back(st[i]);

  cout << str << '\n';
  return 0;

 }
