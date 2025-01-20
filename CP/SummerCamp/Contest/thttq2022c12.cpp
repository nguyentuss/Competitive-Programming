#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	int n = s.size();
	int m;
	cin >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		char x, y;
		cin >> x >> y;
		for (int i = u; i <= v; i++) {
			if (s[i] == x) {
				s[i] = y;
			}
		}
	}
	cout << s;
	return 0;
}