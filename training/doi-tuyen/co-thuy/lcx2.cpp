#include <bits/stdc++.h>
using namespace std;

#define MAX_N (int) (3e3 + 7) 
#define int long long

int a[MAX_N] , b[MAX_N];
int f[MAX_N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n , m; cin >> n >> m;
		for (int i = 1 ; i <= n ; i++) 
			cin >> a[i];
		for (int i = 1 ; i <= m ; i++) {
			f[i] = 0;
			cin >> b[i];
		}
		for (int i = 1 ; i <= n ; i++) {
			int current = 0;
			int tmp = 0;
			for (int j = 1 ; j <= m ; j ++) {
			    tmp = current;
			    if (a[i] >= 2*b[j]) {
					current = max(current , f[j]);
				}
				if (a[i] == b[j]) {
					f[j] = max(f[j] , tmp + 1);
				}
			}
		}
		int ans = 0;
		for (int i = 1 ; i <= m ;i++) {
			ans = max(ans , f[i]);
		}
		cout << ans << '\n';
	}
	return 0;
}