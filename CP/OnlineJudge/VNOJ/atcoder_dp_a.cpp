#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)
#define inf (int) (1e9 + 7)

int f[MAX_N];
int v[MAX_N];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	for (int i = 1 ; i <= n ; i++) {
		cin >> v[i];
		f[i] = inf;
	}
	f[1] = 0;
	for (int i = 1 ; i <= n ; i++) {
		if (i + 1 <= n)
			f[i + 1] = min(f[i + 1] , f[i] + abs(v[i] - v[i + 1]));
		if (i + 2 <= n) 
			f[i + 2] = min(f[i + 2] , f[i] + abs(v[i] - v[i + 2]));
	}
	cout << f[n];
	return 0;
}