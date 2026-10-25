#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>
#define f first 
#define s second

vector <ii> v;

int calc(int x , int y , int k) {
	vector <double> a(k);
	for (int i = 0 ; i < k ; i++) {
		double dy = v[i].s - v[k].s;
		if (dy != 0) {
			a[i] = (v[i].f - v[k].f)/dy;
		}
		else a[i] = 1e9;
	}
	sort(a.begin() , a.end());
	long long res = 0 , cnt = 1;
	for (int i = 1 ; i < k ; i++) {
		if (a[i] != a[i - 1]) {
			res += (cnt*(cnt - 1))/2;
			cnt = 0;
		}
		cnt ++;
	}
	res += (cnt*(cnt - 1))/2;
	return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("badiem.inp","r",stdin);
	freopen("badiem.out","w",stdout);
	int n; cin >> n ;
	for (int i = 0 ; i < n ; i++) {
		int x , y ; cin >> x >> y;
		v.push_back(ii(x ,y));
	}
	long long res = 0;
	for (int i = 2 ; i < n ; i++) 
		res += calc(v[i].f , v[i].s , i);

	cout << res;
	return 0;
}