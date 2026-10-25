#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e4 + 7)
#define int long long

int a[MAX_N];
signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("happyfarm.inp","r",stdin);
	freopen("happyfarm.out","w",stdout);
	int n , x; cin >> n >> x;
	for (int i = 1 ; i <= n ; i++) {
		cin >> a[i];
		a[i] = a[i]*(n - i + 1);
	}
	sort(a + 1 , a + 1 + n);
	int total = 0 , cnt = 0;
	for (int i = 1 ; i <= n ; i++) {
		if (total + a[i] > x) {
			cout << cnt;
			return 0;
		}
		else {
			total += a[i];
			cnt++;
		}
	}	
	cout <<cnt;
	return 0;
}