#include <bits/stdc++.h>

using namespace std;

set<int , greater<int>> s;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("snowman.inp","r",stdin);
	freopen("snowman.out","w",stdout);
	int n; cin >> n;
	for (int i = 0 ; i < n ; i++) {
		int x; cin >> x;
		s.insert(x);
	}
	cout << s.size()/3 << '\n';
	int cnt = 0;
	if (s.size()/3 == 0) return 0;
	for (auto it : s) {
		cnt++;
		cout << it << " ";
		if ((s.size()/3)*3 == cnt) return 0;
		if (cnt % 3 == 0) cout << '\n';
	}
	return 0;
}