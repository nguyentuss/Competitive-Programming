#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast") 

map<char,int> m;

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);

	int count = 0;
	for (int i = 'a' ; i <= 'z' ; i ++)  
		m[i] = ++count;
	string s;
	cin >> s;
	int num; cin >> num;
	int ans = 0;
	for (auto e : s) 
		ans += (num + m[e] - 1)%26;

	cout << ans;
	return 0;
}