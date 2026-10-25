#include <bits/stdc++.h>

using namespace std;

vector<int> v;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	for (int i = 0 ; i < n ; i ++) {
		int x; cin >> x;
		v.push_back(x);
	}
	int l = 0 , ans = 0;
	for (int i = 1 ; i < n ; i++) {
		if (v[l] < v[i]) {
			ans += v[i] - v[i - 1];
		}
		if (v[i] >= v[i - 1] && v[i] >= v[i + 1]) {
			l = i;
		}
	}
	cout << ans;
	return 0;
}