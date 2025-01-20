#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	int change = 0;
	char l , r;
	int ans = 0;
	char x; cin >> x;
	l = x , change++ , n--;
	while (n--) {
		char x; cin >> x;
		if (x != '?') {
			if (change) r = x;
			change ++;
		}
		if (change == 2) {
			if (l == 'a' && r == 'b') ans ++;
			else if (l == 'b' && r == 'a') ans--;
			change = 1;
			l = r;
		}
	}
	cout << ans;
	return 0;
}