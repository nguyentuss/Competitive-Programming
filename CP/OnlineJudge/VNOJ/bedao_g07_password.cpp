#include <bits/stdc++.h>

using namespace std;

#define MIN_N (int) (-2e9)

int n;

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	int res = MIN_N;
	for (int i = 0 ; i < n ; i++) {
		int x; cin >> x;
		res = max(res , x);
	}
	cout << res;
	return 0;
}