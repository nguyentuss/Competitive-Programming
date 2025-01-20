#include <bits/stdc++.h>

using namespace std;

vector<int> v;
int n , x;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("inp.inp","r",stdin);
	//freopen("out.out","w",stdout);
	cin >> n >> x;
	for (int i = 0 ; i < n ; i++) {
		int k; cin >> k;
		v.push_back(k);
	}
	long long ans = 0;
	int l = 0 , r = n - 1;
	while (l < n) {
		while (v[l] + v[r] > x && l < r) r--;
		if (l >= r) break;
		ans += max(0 , r - l);
		l++;
	}
	cout << ans;
	return 0;
}