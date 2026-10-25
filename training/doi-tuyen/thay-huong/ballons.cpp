#include <bits/stdc++.h>

using namespace std;

map<int ,int> m;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("ballons.inp","r",stdin);
	freopen("ballons.out","w",stdout);
	int n; cin >> n;
	int ans =0 ;
	for (int i = 1 ; i <= n ; i++) {
		int x; cin >> x;
		if (m[x]) m[x] --;
		else ans++;
		if (x - 1 >= 0) m[x - 1]++;
	}
 	cout << ans;
	return 0;
}