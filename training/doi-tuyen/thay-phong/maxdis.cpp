#include <bits/stdc++.h>

using namespace std;

#define MAX_N (long long) (1e5 + 7)

long long x[MAX_N] , y[MAX_N];

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL); cout.tie(NULL);
	long long n ; cin >> n;
	for (long long i = 1 ; i <= n ; i++) 
		cin >> x[i] >> y[i];
	long long p = 1LL;
	long long maximum = LLONG_MIN;
	for (long long i = 1 ; i <= n; i++) {
		long long xi = x[i] , yi = y[i];
		long long dis = (x[p] - xi)*(x[p] - xi) + (y[p] - yi)*(y[p] - yi);
		while (true) {
			long long itmp = (p % n) + 1;
			long long dtmp = (x[itmp] - xi)*(x[itmp] - xi) + (y[itmp] - yi)*(y[itmp] - yi);
			if (dtmp <= dis) break;
			dis = dtmp;
			p = itmp;
		}
		maximum = max(maximum , dis);
	}
	cout << maximum;
	return 0;
}