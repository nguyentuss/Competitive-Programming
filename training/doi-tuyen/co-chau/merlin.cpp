#include <bits/stdc++.h>

using namespace std;

#define int long long
int a[100007];
int total = 0;
map<int , bool> m;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("merlin.inp","r",stdin);
	freopen("merlin.out","w",stdout);
	int n; cin >> n;
	for (int i = 1 ; i <= n ; i++) {
		cin >> a[i];
		total += a[i];
		m[a[i]] = true;
	}
	sort(a + 1 , a + 1 + n , greater<int>());
	if (m.size() == 1) {
		cout << 0; 
		return 0;
	}
	if (total % n == 0) cout << 
	if (total % n != 0 && (total - a[1])%(n - 1) == 0) {
		cout <<
	}
	int cnt = 1;
	int ans = 1;
	int sz = n - 1;
	total -= a[1];	
	while (total % sz != 0) {
		ans++;
		total -= a[++cnt];
		sz--;
		//cout << total << " " << sz << " " << ans << '\n';
	}
	cout << ans;
	return 0;
}