#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MAX_N (int) (1e6 + 7)
#define inf (int) (1e18 + 7)

int a[MAX_N];
int IT[4*MAX_N];
int f[MAX_N] , g[MAX_N] , L[MAX_N] , R[MAX_N];

void update(int x , int val) {
	for (; x < 4*MAX_N ; x += x&-x) IT[x] += val;
}

int get(int x) {
	int ans = 0;
	for (; x > 0 ; x -= x&-x) ans += IT[x];
	return ans;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	for (int i = 1 ; i <= n ; i++) {
		cin >> a[i];
	}
	for (int i = n ; i >= 1 ; i--) {
		int x = a[i];
		f[x] = get(x - 1);
		update(x , 1);
	}	
	for (int i = 1 ; i <= n ; i++) {
		int x = a[i];
		g[x] = i - x + f[x];
	}
	for (int i = 1 ; i <= n ; i++) {
		L[i] = L[i - 1] + f[i];
	}
	for (int i = n ; i >= 1 ; i--) {
		R[i] = R[i + 1] + g[i];
	}
	int ans = inf;
	for (int i = 1 ; i <= n ; i++) {
		ans = min(ans , L[i - 1] + R[i + 1]);
	}
	cout << ans;
	return 0;
}