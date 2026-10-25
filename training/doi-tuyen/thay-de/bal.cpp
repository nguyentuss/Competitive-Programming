#include <bits/stdc++.h>

using namespace std;

int m[1000007];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("bal.inp","r",stdin);
	freopen("bal.out","w",stdout);
	int n; cin >> n;
	int ans =0 ;
	for (int i = 1 ; i <= n ; i++) {
		int x; cin >> x;
		m[x]++;
		if (m[x + 1]) {
			m[x + 1]--;
		}
		else ans++;
	}
 	cout << ans;
	return 0;
}