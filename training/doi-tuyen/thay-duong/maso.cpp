#include <bits/stdc++.h>

using namespace std;


int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("maso.inp","r",stdin);
	freopen("maso.out","w",stdout);
	int n , k; cin >> n >> k;
	vector <bool> P(80007);
	for (int i = 1 ; i <= n ; i++) {
		int x; cin >> x;
		P[x] = true;
	}
	int cnt = 0;
	for (int i = 1 ; i <= 80000 ; i++) {
		if (!P[i]) {
			cout << i << '\n';
			cnt ++;
		}
		if (cnt == k) return 0;
	}
	return 0;
}