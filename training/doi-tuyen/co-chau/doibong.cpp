#include <bits/stdc++.h>

using namespace std;

int a[1007];

long double calc(int k , int n) {
	long double res = 1;
	for (int i = 1 ; i <= k ; i++ , n --) {
		res = res*(long double)n/i;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("doibong.inp","r",stdin);
	freopen("doibong.out","w",stdout);
	int n , m , h; cin >> n >> m >> h;
	int total = 0;
	for (int i = 1 ; i <= m ; i++) {
		cin >> a[i];
		total += a[i];
	}
	if ((n - 1) > (total - 1)) cout << -1;
	else cout << (long double) (1 - (long double) (calc(n - 1, total - a[h]))/((long double)calc(n - 1 , total - 1)));

	return 0;
}