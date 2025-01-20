#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e6 + 7)

bool b[MAX_N];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("WC6.inp","r",stdin);
	freopen("WC6.out","w",stdout);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 1 ; i <= n ;i++) {
			b[i] = false;
		}
		int similar , last;
		for (int i = 1 ; i <= n ; i++) {
			int x; cin >> x;
			if (!b[x]) {
				b[x] = true;
			}
			else {
				similar = x;
			}
		}
		for (int i = 1 ; i <= n ; i++) {
			if (!b[i]) {
				cout << similar << " " << i << '\n';
				break;
			}
		}
	}
	return 0;
}