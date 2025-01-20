#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e6 + 7)

int n;
int f[MAX_N] , v[MAX_N] , pos[MAX_N];

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1 ; i <= n ; i++) {
		cin >> v[i];
		pos[v[i]] = i;
		f[v[i]] = 1;
	}
	f[1] = 1;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 2*v[i] ; j <= n ; j+= v[i]) {
			if (pos[v[i]] < pos[j]) {
				f[j] = max(f[j] , f[v[i]] + 1);
			}
		}
	}
	int ans = 1;
	for (int i = 1 ; i <= n ; i++) {
		//cout << f[v[i]] << " ";
		ans = max(ans , f[v[i]]);
	}
	cout << ans;
	return 0;
}