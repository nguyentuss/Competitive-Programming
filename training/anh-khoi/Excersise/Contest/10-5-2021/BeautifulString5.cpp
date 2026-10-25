#include <bits/stdc++.h>

using namespace std;

map<char , long long> m;


int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	
	int n; cin >> n;
	for (int i = 1 ; i <= n ;i++) {
		int x; cin >> x;
		for (int j = 0 ; j < x ; j++) cout << 'a';
		cout << '\n';
	}

	return 0;
}