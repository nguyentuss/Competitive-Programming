#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (100)

int v[MAX_N] , b[MAX_N];
int sum[MAX_N];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("keypad.inp","r",stdin);
	freopen("keypad.out","w",stdout);
	int n; cin >> n;
	for (int i = 1 ; i <= n ;i ++) {
		cin >> v[i];
	}
	int k; cin >> k;
	for (int i = 1 ; i <= k ; i++) {
		cin >> b[i];
	}
	sort(v + 1 , v + 1 + n , greater<int>());
	int l = 1 , r = 0;
	int multi = 0;
	int ans = 0;
	while (true) {
		multi++;
		int cnt = 0;
		for (int i = 1 ; i <= k ; i++) {
			if (b[i] > 0) cnt++;
		}
		if (!cnt) break;
		for (int i = l ; i <= (l + cnt - 1) && i <= n ; i++) {
			ans += v[i]*multi;
		}
		l = l + cnt;
		for (int i = 1 ; i <= k ; i++) {
			b[i]--;
		}
	}
	cout << ans;
	return 0;
}