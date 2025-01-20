#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.inp","r",stdin);
	int t; cin >> t;
	while (t--) {
		string n; cin >> n;
		int ans = n.size();
		for (int i = 0 ; i < n.size() ; i++) {
			for (int j = i + 1 ; j < n.size() ; j++) {
				int x = (n[i] - '0')*10 + (n[j] - '0');
				if (x % 25 == 0) {
					int len = n.size();
					//cout << x << " " <<  i << " " << j << '\n';
					ans = min(ans , j - i - 1 + (len - 1) - j);
				}	
			}
		}
		cout << ans << '\n';
	}
	return 0;
}