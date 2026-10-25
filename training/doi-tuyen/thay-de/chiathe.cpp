#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (507)
#define MAX_D (int) (1e5 + 7) 
#define inf (int) (1e9 +7)
int f[MAX_N][MAX_D];
int n;
int a[MAX_N];
int sum = 0;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1 ; i <= n ;i++) {
		cin >> a[i];
		sum += a[i];
	}
	for (int i = 0 ; i <= n ; i++) {
		for (int j = 0 ; j <= sum ; j++) {
			f[i][j] = inf;
		}
	}
	f[0][0] = 0;
	for (int i = 0 ; i <= n ; i++) {
		for (int j = 0 ; j <= sum ; j++) {
			if (f[i][j] == inf) continue;
			f[i + 1][abs(j - a[i + 1])] = min(f[i + 1][abs(j - a[i + 1])] , f[i][j]);
			f[i + 1][abs(j + a[i + 1])] = min(f[i + 1][abs(j + a[i + 1])] , f[i][j]);
			f[i + 1][j] = min(f[i + 1][j] , f[i][j] + a[i + 1]); 
		}
	}
	cout << f[n][0] + (sum - f[n][0])/2;
	return 0;
}