#include <iostream>
#include <string>

using namespace std;

int main(){
	freopen("noihaiso.inp","r",stdin);
	freopen("noihaiso.out","w",stdout);
	string s1,s2;
	cin >> s1 >> s2;
	cout << ((s1+s2<s2+s1)?(s2+s1):(s1+s2));
	return 0;
}