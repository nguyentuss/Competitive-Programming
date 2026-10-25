#include <bits/stdc++.h>

using namespace std;

int n , m;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	cout.tie(NULL);
	freopen("tknp.inp","r",stdin);
	freopen("tknp.out","w",stdout);
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++) {
		int x; cin >> x;
		v.push_back(x);
	}
	int l = 0 , r = n - 1;
	while (l <= r) {
		int mid = (l + r)/2;
		if (v[mid] > m) 
			r = mid - 1;
		else if (v[mid] < m) 
			l = mid + 1;
		else return (cout << mid + 1 , 0);
	}
	cout << -1;
	return 0;
}