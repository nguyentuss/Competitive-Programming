#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (2*1e5 + 7)

int a[MAX_N] , cnt1[MAX_N] , cnt2[MAX_N];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >>n;
	for (int i = 1 ; i <= n; i++) {
		cin >> a[i];
	}
	cnt1[0] , cnt2[n + 1] = 0;
	for (int i = 1;  i <= n ; i++) 
		cnt1[i] = cnt1[i - 1] + (a[i] == 1);
	for (int i = n ; i >= 1 ; i--) 
		cnt2[i] = cnt2[i + 1] + (a[i] == 2);
	int ans = INT_MAX;
	for (int i = 1 ; i <= n; i++) {
		ans = min(ans , n - (cnt1[i] + cnt2[i]));
	}
	cout << ans;
	return 0;
}