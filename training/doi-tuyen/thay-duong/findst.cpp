#include <bits/stdc++.h>

using namespace std;

int f[507][256];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("findst.inp","r",stdin);
	freopen("findst.out","w",stdout);
	int t; cin >> t;
	while (t--) {
		int n , m; cin >> n >> m;
		memset(f , 0 , sizeof f);
		for (int i = 1 ; i <= n ;i++) {
			for (int j = 1 ; j <= m ;j++) {
				char x; cin >> x;
				f[i][(int) x]++;
			}
		}
		string s; cin >> s;
		int len = s.size();
		s = '0' + s;
		int cnt = 1;
		bool found = false;
		for (int i = 1 ; i <= len ; i++) {
			if (!f[cnt][s[i]]) {
				found = true;
				cout << "No" << '\n';
				break;
			}
			f[cnt][(int) s[i]]--;
			if (cnt == n) cnt = 1;
			else cnt++;
		}
		if (!found) cout << "Yes" << '\n';
	}
	return 0;
}