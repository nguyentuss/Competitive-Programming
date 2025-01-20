#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n , x; cin >> n;
		int ans = 0;
		int cntone = 0;
		for (int i = 1 ; i <= n; i++) {
			cin >> x;
			ans ^= x;
			if (x == 1) cntone ++;
		}
		if (cntone == n) 
			cout << ((cntone & 1) ? -1 : 1) << '\n';
		else cout << (ans ? 1 : -1) << '\n';
		
	}
	return 0;
}