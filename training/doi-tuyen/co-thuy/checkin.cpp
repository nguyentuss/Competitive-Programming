#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (100007)
#define int long long

int n , m;
int a[MAX_N];

bool check(int x) {
	int sum = 0;
	for (int i = 1 ; i <= n ; i++) {
		sum += x/a[i];
	}
	if (sum >= m) return true;
	return false;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("checkin.inp","r",stdin);
	freopen("checkin.out","w",stdout);
	cin >> n >> m;
	for (int i = 1 ; i <= n ;i++) {
		cin >> a[i];
	}
	int l = 1 , r = 1e18;
	int ans = 0;
	while (l <= r) {
		int mid = (l + r)/2;
		if (check(mid)) {
			r = mid - 1;
			ans = mid;
		}
		else {
			l = mid + 1;
		}
	}
	cout << ans;
	return 0;
}