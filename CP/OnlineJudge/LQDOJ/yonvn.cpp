#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	int a , b , s;
	cin >> a >> b >> s;
	int go = abs(a) + abs(b);
	if (go <= s && (go - s)%2 == 0) cout << "Yes";
	else cout << "No";	
	return 0;
}