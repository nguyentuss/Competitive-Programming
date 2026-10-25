#include <bits/stdc++.h>

using namespace std;

vector<int> v;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	freopen("gift.inp","r",stdin);
	freopen("gift.out","w",stdout);
	cout.tie(NULL);
	int n, m; cin >> n >> m;
	for (int i = 1 ; i <= m ; i ++) {
		int x; cin >> x;
		v.push_back(x);
	}
	sort(v.begin() , v.end());
	int total = 0;
	int cnt = 0;
	for (auto x : v) {
		total += x;
		if (total <= n) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}