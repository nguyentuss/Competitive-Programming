#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)
#define int long long

int a[MAX_N] , n , k;

bool check(int x) {
	int r = 0 , last = k;
	for (int i = 1 ; i <= n ;i++) {
		if (a[i] > r) {
			r = a[i] + x*2;
			last --;
			if (last < 0) return false;
		}
	}
	return true;
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	freopen("light.inp","r",stdin);
	freopen("light.out","w",stdout);
	cin >> n >> k;
	for (int i = 1 ; i <= n ;i++)		
		cin >> a[i];
	sort(a + 1 , a + 1 + n);
	int l = 0 , r = 1e9 , ans = 0;
	while (l <= r) {	
		int mid = (l + r)/2;
		if (check(mid)) {
			r = mid - 1;
			ans = mid;
		}
		else l = mid + 1;
	}
	cout << ans;

	return 0;
}