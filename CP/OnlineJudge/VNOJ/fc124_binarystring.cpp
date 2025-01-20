#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("binarystr.inp","r",stdin);
	//freopen("binarystr.out","w",stdout);
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		int l = -1 , r = -1;
		bool check = false;
		for (int i = 0 ; i < s.size() ;i++) {
			if (s[i] == '1' && !check) {
				l = r = i;
				check = true;
			}
			else if (s[i] == '1' && check) {
				r = i;
			}
		}
		if (l == -1 && r == -1) {
			cout << -1 << '\n';
			continue;
		}
		int ans = 0;
		for (int i = l ; i < r ; i++) 
			if (s[i] == '0') ans++;
		cout << ans << '\n';
	}
	return 0;
}