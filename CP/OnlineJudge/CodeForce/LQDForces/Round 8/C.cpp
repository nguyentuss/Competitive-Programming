#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long 
#define MAX_N (int) (500007)
#define inf (int) (1e18 + 7)
 
int v[MAX_N];
int POW[MAX_N];
int n , m; 
int calc(int x) {
	POW[0] = 1;
	for (int i = 1 ; i <= m ; i++) {
		if (v[i] >= x) return 1;
	}
	int ans = 0;
	for (int i = 1 ; i <= m ; i++) {
		ans += v[i]*POW[i - 1];
		if (ans < 0) return 0;
		if (v[i + 1] > 0 && ans + x > n) return 0;
		POW[i] = POW[i - 1]*x;
		if (ans > n) return 0; 
	}
	if (ans < n) return 1;
	return 2;
}
 
signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.inp","r",stdin);
	cin >> n >> m;
	for (int i = 1 ; i <= m ; i++) {
		cin >> v[i];
	}
	int l = 1 , r = 1e18;
	int ans = inf;
	while (l <= r) {
		int mid = (l + r)/2;
		int x = calc(mid);
		if (x == 0) r = mid - 1;
		if (x == 1) l = mid + 1;
		if (x == 2) {
			ans = min(ans , mid);
			r = mid - 1;
		}
	}
	/*int ans = inf;
	for (int i = 1 ; i <= 16 ; i++) {
		int x = calc(i);
		if (x == 2) ans = min(ans , i);
	}*/
 	if (ans == inf) cout << -1;
 	else cout << ans;
	return 0;
}