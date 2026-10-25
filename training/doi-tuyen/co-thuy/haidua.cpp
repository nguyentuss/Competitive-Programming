#include <bit/stdc++.h>

using namespace std;

#define MAX_N (int) (1e2 + 7)

int a[MAX_N] , b[MAX_N] , c[MAX_N] , d[MAX_N];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	int n; cin >> n;
	for (int i = 1 ; i <= n ; i++) {
		cin >> a[i] >> b[i];
	}
	int m; cin >> m;
	for (int i = 1 ; i <= m ; i++) {
		cin >> c[i] >> d[i];
	}
	int l = 1 ; r = t;
	while (l <= r) {
		int mid = (l + r)/2;
		if (check)
	}
	return 0;
}