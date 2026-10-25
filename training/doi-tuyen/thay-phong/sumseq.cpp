#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (3e5 + 7)
#define int long long


int sum[MAX_N];
int a[MAX_N];

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	cout.tie(NULL);
	freopen("test.inp","r",stdin);
	int n , x; cin >> n >> x;
	for (int i = 1; i <= n ; i++) {
		cin >> a[i];
	}
	int sum = 0 , maxi = LLONG_MIN , mini = LLONG_MAX;
	int l = 1 , r = 1;
	int left = 1 , right = 1;
	for (int i = 1; i <= n ;i++) {
		sum += a[i];
		maxi = max(maxi , sum);
		if (sum < 0) {
			maxi = max(maxi , sum - a[i]);
			sum = 0;
		}
	}
	sum = 0;
	for (int i = 1 ; i <= n ;i++) {
		sum += a[i];
		if (mini > sum) {
			mini = sum;
			r = i;
			right = i;
			left = l;
		}
		if (sum > 0) {
			if (mini > (sum - a[i])) {
				mini = sum - a[i];
				right = i - 1;
				left = l;
			}
			l = i + 1;
			sum = 0;
		}
	}
	if (x <= 0) {
		int lmax = 0 , rmax = 0;
		sum = 0;
		for (int i = left - 1 ; i >= 1 ; i--) {
			sum += a[i];
			lmax = max(lmax , sum);
		}
		sum = 0;
		for (int i = right + 1 ; i <= n ; i++) {
			sum += a[i];
			rmax = max(rmax , sum);
		}
		//cout << lmax << " " << rmax << '\n';
		cout << mini*x + lmax + rmax;
	}
	else cout << maxi*x;

	return 0;
}