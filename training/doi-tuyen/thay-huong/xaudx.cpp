#include <bits/stdc++.h>

using namespace std;

string str;

int main(){	
	ios::sync_with_stdio(0); cin.tie(NULL);
	freopen("xaudx.inp","r",stdin);
	freopen("xaudx.out","w",stdout);

	cin >> str;
	string temp = str;
	reverse(temp.begin() , temp.end());
	cout << ((temp == str)?"YES":"NO");

	return 0;
}