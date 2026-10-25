#include <bits/stdc++.h>
#include <fstream>
using namespace std;

string str;

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	//freopen("thutu.inp","r",stdin);
	//freopen("thutu.out","w",stdout);
	cin >> str;
	reverse(str.begin() , str.end());
	unsigned long long ans = 0;
	unsigned long long before = 1;
	for (int i = 0 ; i < (int) str.size() ; i++) {
		ans += (str[i] - 'a' + 1)*before;
		before *= 26;
	}
	cout << ans;
	return 0;
}