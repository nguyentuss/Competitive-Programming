#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (2*1e5 + 7)
#define int long long
#define inf (int) (1e18)

int v[MAX_N];
int sum[MAX_N];
int n , s;
int P[MAX_N][20];

void rmq() {
	for (int k = 1 ; (1 << k) <= n ; k++) {
		for (int i = 1 ; i + (1 << k) - 1 <= n ; i++) {
			P[i][k] = min(P[i][k - 1] , P[i + (1 << (k - 1))][k - 1]);
		}
	}
}

int get(int l , int r) {
	int k = log2(r - l + 1);
	return min(P[l][k] , P[r - (1 << k) + 1][k]);
}

bool check(int x) {
	int l = 1 , r = x;
	while (r <= n) {
		if (s + get(l , r) - sum[l - 1] >= 0) return true;
		l++ , r++; 
	}
	return false;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.inp","r",stdin);
	int t; cin >> t;
	while (t--) {
		cin >> n >> s;
		for (int k = 0 ; (1 << k) <= n ; k++) {
			for (int i = 1 ; i + (1 << k) - 1 <= n ; i++) {
				P[i][k] = inf;
			}
		}
		for (int i = 1 ; i <= n ; i++) {
			cin >> v[i];
			sum[i] = sum[i - 1] + v[i];
			P[i][0] = sum[i];
		}
		rmq();
		int l = 0 , r = n; 
		int ans = 0;
		while (l <= r) {
			int mid = (l + r)/2;
			if (check(mid)) {
				l = mid + 1;
				ans = mid;
			}
			else {
				r = mid - 1;
			}
		}
		if (!ans) cout << -1 << '\n';
		else {
			int l = 1 , r = ans;
			while (r <= n) {
				if (s + get(l , r) - sum[l - 1] >= 0) {
					cout << l << " " << r << '\n';
					break;
				}
				l++ , r++;
			}
		}
	}

	return 0;
}