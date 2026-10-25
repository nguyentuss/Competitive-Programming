#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)
#define inf (int) (1e18 + 7)
#define int long long

int prsum[MAX_N] , susum[MAX_N];
int f1[MAX_N] , f2[MAX_N];
int a[MAX_N];

signed main( ){
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("subseq.inp","r",stdin);
	freopen("subseq.out","w",stdout);
	int n , k; cin >> n >> k;
	for (int i = 1 ; i <= n ; i++) {
		cin >> a[i];
	}
	for (int i = 1 ; i <= n ; i++) 
		prsum[i] = prsum[i - 1] + a[i];
	for (int i = n ; i >= 1 ; i --) 
		susum[i] = susum[i + 1] + a[i];
	for (int i = k ; i <= n ; i++) {
		int x = prsum[i] - prsum[i - k];
		f1[i] = max(f1[i - 1] , x);
	}
	for (int i = n - k + 1; i >= 1 ; i--) {
		int x = susum[i] - susum[i + k];
		f2[i] = max(f2[i + 1] , x);
	}
	int ans = inf;
	for (int i = k ; i <= n ; i++) {
		int x = prsum[i] - prsum[i - k];
		if (f1[i - k] <= x && f2[i + 1] <= x) {
			ans = min(ans , x);
		}
	}
	cout << ans;
	return 0;
}