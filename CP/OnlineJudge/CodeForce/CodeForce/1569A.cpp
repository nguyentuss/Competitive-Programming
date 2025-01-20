#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (100)

int numberofA[MAX_N] , numberofB[MAX_N];
string s;

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);

	int t;cin >> t;
	while (t--) {
		int n; cin >> n;
		cin >> s;
		int l = 0 , r = 1;
		bool check = false;
		while (r < n) {
			if ((s[l] == 'a' && s[r] == 'b') || (s[l] == 'b' && s[r] == 'a')) {
				cout << l + 1 << " " << r + 1 << '\n';
				check = true;
				break;
			}
			else {
				l ++ , r ++;
			}
		} 
		if (!check) cout << -1 << " " << -1 << '\n';
	}

	return 0;
}