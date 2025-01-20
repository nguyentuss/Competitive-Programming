#include <bits/stdc++.h>

using namespace std;

int n, x;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> x;
	for (int i = 0 ; i < n ;i++) {
		int tmp; cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin() , v.end());
	int l = 0 , r = n - 1;
	int ans = 0;
	while (l <= r) {
		if (v[l] + v[r] <= x) l++ , r--;
		else r--;
		ans ++;
	}
	cout << ans;
	return 0;
}