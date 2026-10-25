#include <bits/stdc++.h>

using namespace std;

int v[10000] , f[10000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int n; cin >> n;
	for (int i = 1 ; i <= n ; i++) {
		cin >> v[i];
	}
	int p; cin >> p;
	for (int i = 1 ; i <= n ; i++){ 
		v[i] -= p;
		f[i] = f[i - 1] + v[i];
	}
	for (int i = 1 ; i <= n ; i++) {
		for (int j = )
	}

	return 0;
}