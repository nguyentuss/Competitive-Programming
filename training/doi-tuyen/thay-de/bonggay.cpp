#include <bits/stdc++.h>

using namespace std;

#define ii pair<int ,int>
#define f first
#define s second
#define int long long

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("bonggay.inp","r",stdin);
	freopen("bonggay.out","w",stdout);
	int m , n; cin >> m >> n;
	vector<ii> v;
	int time = m*6;
	for (int i = 1 ; i <= n ; i++) {
		int x , y; cin >> x >> y;
		v.push_back(ii(x , y));
	}
	sort(v.begin() , v.end() , greater<ii>());
	int ans = 0;
	for (auto x : v) {
		if (time > 0) {
			ans += x.f*min(x.s , time);
			time -= x.s;
		}
	}
	cout << ans;
	return 0;
}