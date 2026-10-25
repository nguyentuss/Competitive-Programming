#include <bits/stdc++.h>

using namespace std;

int cost[50][50];
bool C[50];
int X[50];
int ans = INT_MAX;
int n;

void isfound() {
	int res = 0;
	for (int i = 1 ; i < n ; i++) {
		res += cost[X[i]][X[i + 1]];
	}
	if (ans > res) {
		ans = res;
		/*for (int i = 1 ; i <= n ; i++) cout << X[i] << " ";
			cout << '\n';
		cout << res << '\n';*/
	}
}

void backtr(int i) {
	for (int j = 1 ; j <= n ; j++) {
		if (!C[j]) {
			C[j] = true;
			X[i] = j;
			if (i == n) isfound();
			else {
				backtr(i + 1);
			}
			C[j] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	cin >> n;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= n ; j++) {
			cin >> cost[i][j];
		}
	}
	backtr(1);
	cout << ans;
	return 0;
}