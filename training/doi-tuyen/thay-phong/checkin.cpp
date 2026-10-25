#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX_N (int) (1e5 + 7)

int n;
ll m;
ll a[MAX_N];

bool check(ll x) {
	ll total = 0LL;
	for (int i = 1 ; i <= n ; i++) {
		total += x / a[i];
		if (total >= m) return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++) cin >> a[i];
	ll l = 1LL , r = 1e18 , ans;
	while (l <= r) {
		ll mid = (l + r)/2;
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		}	
		else l = mid + 1;
	} 
	cout << ans;
	return 0;
}