#include <bits/stdc++.h>

using namespace std;

#define int long long
int n , m;
vector<int> a(100007);
vector<int> b(100007);

bool check(int mid) {
	int time = (mid + 1)/2;
	int cnt = 0;
	for (int i = 0 ; i < n ; i++) {
		if (a[i] <= b[cnt]) cnt++;
		if (cnt == m) {
			time-- , cnt = 0;
		}
	}
	return (time > 0);
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("journey.inp","r",stdin);
	freopen("journey.out","w",stdout);
 	cin >> n >> m;
	for (int i = 0 ; i < n ; i++) {
		cin >> a[i];
	}
	for (int i = 0 ; i < m ; i++) {
		cin >> b[i];
	}
	sort(a.begin() , a.end());
	sort(b.begin() , b.end());
	int l = 1 , r = 1e9;
	int ans = 0;
	while (l <= r) {
		int mid = (l + r)/2;
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans;
	return 0;
}