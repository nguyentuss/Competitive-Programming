#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)
#define inf (int) (1e9 + 7)

int res[MAX_N] , last[MAX_N];
int v[MAX_N];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	for (int i = 1 ; i <= n ;i++) {
		cin >> v[i];
		last[i] = inf;
	}	
	for (int i = 1 ; i <= n ;i++) {
		res[i] = lower_bound(last + 1 , last + 1 + n , v[i]) - last;
		last[res[i]] = min(last[res[i]] , v[i]);
	}
	int ans = INT_MIN;
	for (int i = 1 ; i <= n ;i++) {
		ans = max(ans , res[i]);
	}
	cout << ans;

	return 0;
}