#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	freopen("square.inp","r",stdin);
	freopen("square.out","w",stdout);
	long long n , m; cin >> n >> m;
	long long l = 1 , r = 1 , cnt = 0 , posx = 0 , posy = 0 , cnt1 = 1;
	for (long long i = 1 ; i <= 2*n - 1 ; i++) {
		if (i <= n) posx = i , posy = 1;
		else {
			posx = n;
			posy = ++cnt1;
		}
		if (l <= m && m <= r) break;
		l = r + 1 , r = l + (i<n?++cnt:--cnt);
	}
	long long tmp = l;
	for (;;) {
		if (tmp == m) {
			cout << posx << " " << posy << '\n';
			return 0;
		}
		else {
			tmp ++;
			posx-- , posy++;
		}
	}
	return 0;
}