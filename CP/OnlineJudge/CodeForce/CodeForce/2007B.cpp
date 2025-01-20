#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T;
	for (cin >> T; T; T--) {
		int n, q; cin >> n >> q;
		int mx = 0;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			mx = max(mx, x);
		}
		while (q--) {
			char c;
			int x, y; cin >> c >> x >> y;
			if (mx >= x && mx <= y) {
				if (c == '+') mx++;
				else mx--;
			}
			cout << mx << ' ';
		}
		cout << '\n';
	}
	return 0;
}