#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);cin.tie(NULL);
	cout.tie(NULL);
	int n , a , b; cin >> n >> a >> b;
	int b2 = 0;
	int res = 0;
	for (int i = 0 ; i < n ; i++) {
		int x ; cin >> x;
		if (x == 1) {
			if (a) a--;
			else if (b) {
				b--;
				b2++;
			}
			else if (b2) b2--;
			else res ++;
		}
		else {
			if (b) b--;
			else res+=2;
		}
	}
	cout << res;
	return 0;
}