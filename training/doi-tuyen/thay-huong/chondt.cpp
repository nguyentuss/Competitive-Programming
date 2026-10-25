#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)
#define x first
#define y second
#define ii pair<int , int>
#define int long long

vector<int> u , v;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("chondt.inp","r",stdin);
	freopen("chondt.out","w",stdout);
	int n; cin >> n;
	for (int i = 1 ; i <= n ; i++) {
		int x , y; cin >> x >>y;
		v.push_back(x);
		u.push_back(y);
	}
	sort(v.begin() , v.end());
	sort(u.begin() , u.end());
	cout << v[v.size()/2] << " " << u[u.size()/2];

	return 0;
}