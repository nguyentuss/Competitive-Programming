#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("inp.inp","r",stdin);
	freopen("out.out","w",stdout);
	int t; cin >> t;
	while (t--) {
		int n , k; cin >> n >> k;
		cout << k << '\n';
		if (n > 1) cout << (k % 2 ?k/2 + (k < 0 ?-1 : 1):k/2) << " " << k/2 << '\n';
		queue <int> q;
		q.push(k % 2?k/2+(k < 0 ?-1 : 1):k/2);
		q.push(k/2);
		for (int i = 1 ; i < n - 1 ; i++) {
			int x = q.front();
			q.pop();
			cout << (x % 2 ? x / 2 + (x < 0 ?-1 : 1) : x/2) << " " << x/2 << " ";
			q.push(x % 2 ? x / 2 + (x < 0 ?-1 : 1) : x / 2) , q.push(x/2);
			int cnt = 0 , prev = x / 2;
			while (cnt < i) {
				cnt ++;
				x = q.front();
				q.pop();
				q.push(x - prev);
				cout << (prev = x - prev) << " ";
			}
			cout << '\n';
		}
	}
	return 0;
}