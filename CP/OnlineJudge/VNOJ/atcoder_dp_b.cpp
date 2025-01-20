#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)
#define inf (int) (1e9 + 7)

int f[MAX_N];
int v[MAX_N];
int k;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n >> k;
	for (int i = 1 ; i <= n ; i++) {
		cin >> v[i];
		f[i] = inf;
	}
	f[1] = 0;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = i + 1 ; j <= i + k ; j++) {
			if (j <= n)
				f[j] = min(f[j] , f[i] + abs(v[i] - v[j]));
		}
	}
	cout << f[n];
	return 0;
}