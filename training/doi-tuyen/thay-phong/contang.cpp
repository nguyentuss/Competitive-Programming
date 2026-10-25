#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (2e3 + 7)

int f[MAX_N] , trace[MAX_N] , v[MAX_N];
int n ;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1 ; i <= n ;i++) {
		cin >> v[i];
		f[i] = 1;
	}
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j < i ; j ++) {
			if (v[i] > v[j]) f[i] = max(f[i] , f[j] + 1);
		}
	}
	int ans = INT_MIN;
	for (int i = 1 ; i <= n ; i ++) {
		ans = max(ans , f[i]);
	}
	cout << ans;
	return 0;
}