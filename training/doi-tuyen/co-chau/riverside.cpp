#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)

int f[MAX_N];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	int n; cin >> n;
	for (int i = 1 ; i <= n ; i++) {
		cin >> v[i];
		f[i] = max(f[i - 1] , v[i]);
		
	}

	return 0;
}