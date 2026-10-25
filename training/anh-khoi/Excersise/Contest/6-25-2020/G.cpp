#include <bits/stdc++.h>

using namespace std;

long long x , y , a , b;

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while(t--) {
		cin >> x >> y >> a >> b;
		if (a > b) swap(a , b);
		long long l = 0 , r = 2e9 + 7;
		long long ans = 0;
		while (l <= r) {
			long long mid = (l + r)/2;
			long long c1 = x - a*mid;
			long long c2 = y - a*mid;
			if (c1 < 0 || c2 < 0) {
				r = mid - 1;
				continue;
			}
			if (a == b) {
				l = mid + 1;
				ans = mid;
				continue;
			}
			if (c1/(b - a) + c2/(b - a) >= mid) {
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		cout << ans << '\n';
	}
	return 0;
}