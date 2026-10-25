#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (5e4 + 7)
#define ll long long

ll a[MAX_N];
ll sum[MAX_N];

int cnp(int l , int r , ll x) {
	ll tmp = sum[l - 1];
	int pos = -1;
	while (l <= r) {
		int mid = (l + r)/2;
		ll total = sum[mid] - tmp;
		if (total == x) {
			pos = mid;
			break;
		}

		else if (total > x) r = mid - 1;
		else l = mid + 1;
	}
	return pos;
}

ll calc(int l , int r) {
	if (l == r) return 0;
	ll total = sum[r] - sum[l - 1];
	if (total % 2 != 0) return 0;
	if (total == 0) return r - l;
	int pos = cnp(l , r , total/2);
	if (pos == -1) return 0;
	ll ans = 0;
	ans = max(calc(l , pos) , calc(pos + 1 , r)) + 1;
	return ans;
}	

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.inp","r",stdin);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 1 ; i <= n ; i++) {
			cin >> a[i];
			sum[i] = sum[i - 1] + a[i];
			//cout << sum[i] << " ";
		}
		//cout << '\n';
		cout << calc(1 , n) << '\n';
	}
	return 0;
}