#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)

int a[MAX_N] , b[MAX_N];
int n , m; 

int cnp(int x) {
	int l = 1 , r = n , mid , ans = 0;
	while (l <= r) {
		mid = (l + r)/2;
		if (a[mid] < x) {
			l = mid + 1;
			ans = mid;
		}
		else r = mid -1;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++) {
		cin >> a[i];
	}

	sort(a + 1 , a + 1 + n);

	for (int i = 1 ; i <= m ; i ++) {
		int x; cin >> x;
		cout << cnp(x) << '\n';
	}

	return 0;
}