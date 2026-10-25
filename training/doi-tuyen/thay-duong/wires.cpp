#include <bits/stdc++.h>

using namespace std;

int n , k;
vector <int> v;

bool check(int X) {
	int cnt = 0;
	for (int i = 0 ; i < n ; i++) {
		cnt += v[i]/X;
	}
	return (cnt >= k?1:0);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("wires.inp","r",stdin);
	freopen("wires.out","w",stdout);
	cin >> n >> k;
	int l = 1 , r = -1;
	for (int i = 0 ;i < n ; i++) {
		int x; cin >> x;
		v.push_back(x);
		r = max(r , x);
	}
	int ans = 0;
	while (l <= r) {
		int mid = (l + r)/2;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}	
	cout << ans;
	return 0;
}