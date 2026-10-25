#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)
#define int long long

int a[MAX_N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("test.inp","r",stdin);
	freopen("test.out","w",stdout);
	int n , k; cin >> n >> k;
	for (int i = 1 ; i <= n ;i++) {
		cin >> a[i];
	}
	sort(a + 1 , a + 1 + n);
	int res = 0;
	for (int i = 1 ; i <= n ;i++){
		for (int j = i - 1 ; j >= 1 ; j --) {
			int l = 1 , r = j - 1;
			int x = k/(a[i] * a[j]);
			int ans = -1;
			while (l <= r) {
				int mid = (l + r)/2;
				if (a[mid] <= x) {
					l = mid + 1;
					ans = mid;
				}
				else r = mid - 1;
			}
			if (ans != -1) res += ans; 
			//cout << res << " " << i << " " << j << '\n';
		}
	}
	cout << res;
	return 0;
}