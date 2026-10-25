#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)
#define inf (int) (1e9 + 7)

int f1[MAX_N] , f2[MAX_N];
int last[MAX_N];
int v[MAX_N];
int n;

void init() {
	for (int i = 0 ; i <= n ;i++) {
		last[i] = inf;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >>n;
	for (int i = 1 ; i <= n ; i++) {
		cin >> v[i];
	}
	init();
	reverse(v + 1 , v + 1 + n);
	for (int i = 1 ; i <= n; i++) {
		f1[i] = lower_bound(last + 1 , last + 1 + n , v[i]) - last;
		last[f1[i]] = min(last[f1[i]] , v[i]);
	}
	for (int i = 1 ; i <= n ; i++) {
		last[i] = 0;
	}
	for (int i = 1 ; i <= n ; i++) {
		f2[i] = lower_bound(last + 1 , last + 1 + n , v[i] , greater<int>()) - last;
		last[f2[i]] = max(last[f2[i]] , v[i]); 
	}
	int ans = 1;
	for (int i = 1 ; i <= n ; i++) {
		ans = max(ans , f1[i] + f2[i] - 1);
		cout << f1[i] << " " << f2[i] << '\n';
	}
	cout << ans;
	return 0;
}