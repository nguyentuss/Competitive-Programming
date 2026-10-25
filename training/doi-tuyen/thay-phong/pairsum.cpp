#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e3 + 7)

int f[MAX_N][MAX_N];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= n ; j++) {
			cin >> f[i][j];
		}
	}
	int x = (f[1][2] + f[1][3] - f[2][3])/2;
	cout << x << " ";
	for (int i = 2 ; i <= n ; i++) {
		cout << f[1][i] - x << " ";
	}

	return 0;
}