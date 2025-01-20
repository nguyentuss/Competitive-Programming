#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	string s; cin >> s;
	int n; cin >> n;
	for (int i = 1 ; i <= n ;i++) {
		string t; cin >> t;
		if (s.size() != t.size()) continue;
		int num_fix = 0;
		for (int i = 0 ; i < s.size() ; i++) {
			if (t[i] != s[i]) num_fix++; 
		}
		if (num_fix <= 2) cout << i << " "; 
	}

	return 0;
}