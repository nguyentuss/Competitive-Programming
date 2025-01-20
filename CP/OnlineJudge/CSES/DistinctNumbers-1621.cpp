#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast")

set<int> s;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	for (int i = 1 ; i <= n ;i++) {
		int x; cin >> x;
		s.insert(x);
	}
	cout << s.size();
	return 0;
}