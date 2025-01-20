#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	string s;
	while (cin >> s) {
		if (s != "[CASE]") break;
		if (s == "[END]") return 0;
		int n; cin >> n;
		if (n % 5 == 2 || n % 5 == 0) cout << "Hanako" << '\n';
		else cout << "Taro" << '\n';
	}

	return 0;
}