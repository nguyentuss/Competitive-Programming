#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)
#define int long long

int sum[MAX_N];
int v[MAX_N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("coins.inp","r",stdin);
	freopen("coins.out","w",stdout);
	int n; cin >> n;
	for (int i = 1 ; i <= n ; i++) {
		cin >> v[i];
	}
	sort(v + 1 , v + 1 + n);
	sum[0] = 0;
	for (int i = 1 ; i <= n ; i++) {
		sum[i] = sum[i - 1] + v[i];
	}
	int l = 1;
	for (int i = 1 ; i <= n ;i++) {
		if (v[i] != v[i + 1]) {
			if ((l - 1) >= 1 && (i + 1) <= n) {
				if (sum[l - 1] == (sum[n] - sum[i])) {
					cout << "YES";
					return 0;
				}
			}
			l = i + 1;
		}
	}
	cout << "NO";
	return 0;
}