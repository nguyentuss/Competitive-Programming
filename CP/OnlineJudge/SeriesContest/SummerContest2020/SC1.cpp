#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	freopen("SC1.inp","r",stdin);
	freopen("SC1.out","w",stdout);
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		bool check = false;
		int n = s.size();
		for (int num = 0 ; num < 9 ; num++) {
			string giai , c; cin >> giai >> c;
			bool trueornot = true;
			for (int i = n - c.size() , k = 0 ; i < n , k < c.size() ; i++ , k++) {
				if (s[i] != c[k]) {
					trueornot = false;
					break;
				}
			}
			if (!check && trueornot) {
				for (int i = 0 ; i < giai.size() - 1 ; i ++) cout << giai[i];
				cout << '\n';
				check = true;
			}
		}
		if (!check) cout << "NONE\n";
	}
	return 0;
}