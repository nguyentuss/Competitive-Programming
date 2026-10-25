#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ii pair<int , int>
#define f first
#define s second

vector<ii> v;
vector<ii> P;
vector<bool> m;
int n , x , y;

long double ccw(ii &a , ii &b , ii &c) {
	long double tmp1 = (b.f - a.f);
	long double tmp2 = (c.s - a.s);
	long double ngarcute = tmp1*tmp2;
	long double tmp3 = (b.s - a.s);
	long double tmp4 = (c.f - a.f);
	long double ngarsiucute = tmp3*tmp4;
	return (ngarcute - ngarsiucute);
}

int get(int i) {
	ii c = ii(x , y);
	return (ccw(v[i] , v[(i + 1)%n] , c) >= 0);
}

int cnp(int l , int r) {
	int mid = 0;
	int left = l , right = r;
	while (left <= right) {
		int mid = (left + right)/2;
		if (get(mid) == get(l)) left = mid + 1;
		else right = mid - 1;
	}
	int tmp = left - l + 1;
	if (!get(l)) tmp = n/2 - tmp ;
	return tmp;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	//freopen("test.inp","r",stdin);
	freopen("tomau.inp","r",stdin);
	freopen("tomau.out","w",stdout);
	int t; cin >> t;
	cin >> n;
	for (int i = 1 ; i <= n ; i++) {
		int x , y; cin >> x >> y;
		v.push_back(ii(x , y));
	}
	int q; cin >> q;
	int X = 0;
	while (q--) {
		cin >> x >> y;
		x ^= t*X*X*X;
		y ^= t*X*X*X;
		bool a = get(0LL);
		bool b = get(n/2);
		int ans = 0;
		if (a == b) ans = a;
		if (cnp(0LL , n/2 - 1) + cnp(n/2 , n - 1) > (n/2)) ans = 1;
		X += ans;
		if (ans) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}

	return 0;
}