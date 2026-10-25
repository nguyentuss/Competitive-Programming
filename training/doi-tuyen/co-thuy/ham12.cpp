#include <bits/stdc++.h>

using namespace std;

string s , a;
int ans = INT_MAX;
int n , m , k;
int calc(int x) {
	int res = 0;
	for (int i = 0 ; i < m && res < ans ; i ++ , x++) {
		if (x == n) x = 0;
		res += (s[x] != a[i]);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.inp","r",stdin);
	cin >> n >> m >> k;
	cin >> s;
	while (k--) {
		cin >> a;
		for (int i = 0 ; i < n ; i++) {
			ans = min(ans , calc(i));
		}
	}
	cout << ans;
	return 0;
}