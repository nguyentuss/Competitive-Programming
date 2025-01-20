#include <bits/stdc++.h>

using namespace std;

unordered_map<int ,int> m;
string s;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> s;
	for (auto e : s) m[e]++;
	for (auto e : s) {
		cout << m[e] << " ";
		m[e] --;
	}
	return 0;
}