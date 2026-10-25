#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (2e5 + 7)
#define inf (int) (1e9 + 7)
#define int long long

int a[MAX_N];
int P[MAX_N][100];
int n , h;

void rmq() {
	for (int i = 1 ; i <= n ; i++) {
		P[i][0] = a[i];
	}
	for (int j = 1 ; (1 << j) <= n ; j++) {
		for (int i = 1 ; i + (1 << j) - 1 <= n ; i++) {
			P[i][j] = max(P[i][j - 1] , P[i + (1 << (j - 1))][j - 1]);
		}
	}
}

int get(int l , int r) {
	int k = log2(r - l + 1);
	return max(P[l][k] , P[r - (1 << k) + 1][k]);
}

int f[MAX_N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("biendoi.inp","r",stdin);
	freopen("biendoi.out","w",stdout);
	cin >> n >> h;
	for (int i = 1 ; i <= n ; i++) {
		cin >> a[i];
		f[i] = f[i - 1] + a[i];
		a[i] -= i;
	}
	rmq();
	int l = 1 , r = h;
	int ans = inf;
	while (r <= n) {
		int x = get(l , r);
		if (x <= h - r) {
			ans = min(ans , h*(h + 1)/2 - (f[r] - f[l - 1]));
		}
		l++ , r++;
	}
	cout << (ans == inf ? -1 : ans);
	return 0;
}