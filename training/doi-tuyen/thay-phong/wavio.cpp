#include <bits/stdc++.h>

using namespace std;

#define inf (int) (1e9 + 7)
#define MAX_N (int) (2e3 + 7)

int v[MAX_N];
int f1[MAX_N];
int f2[MAX_N];
int last[MAX_N];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	if (n == 1) {
		cout << 1;
		return 0;
	}
	for (int i = 1 ; i <= n ; i++) {
		cin >> v[i];
		last[i] = inf;
	}
	last[0] = inf;
	for (int i = 1 ; i <= n ; i++) {
		f1[i] = lower_bound(last + 1 , last + 1 + n , v[i]) - last;
		last[f1[i]] = min(last[f1[i]] , v[i]);
	}
	reverse(v + 1 , v + 1 + n);
	for (int i = 1 ; i <= n ; i++) {
		last[i] = inf;
	}
	for (int i = 1 ; i <= n ; i++) {
		f2[i] = lower_bound(last + 1 , last + 1 + n , v[i]) - last;
		last[f2[i]] = min(last[f2[i]] , v[i]);
	}
	reverse(f2 + 1 , f2 + 1 + n);
	int ans = 0;
	for (int i = 1 ; i <= n ; i++) {
		ans = max(ans , f1[i] + f2[i] - 1);
	}
	cout << ans;

	return 0;
}
