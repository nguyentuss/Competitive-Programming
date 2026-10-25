#include <bits/stdc++.h>

using namespace std;

int main(){ 	
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("trip.inp","r",stdin);
	freopen("trip.out","w",stdout);
	int n , d; cin >> n >> d;
	vector <int> v;
	int x;
	for (int i = 0 ; i < n ; i ++) {
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin() , v.end());
	int l = 0 , r = n - 1;
	int ans = 0;
	for (int i = 0 ; i < n ; i++) {
		if (l <= r) ans ++;
		if (v[l] + v[r] > d) 
			r--;
		else {
			l++;
			r--;
		}
	}
	cout << ans;

	return 0;
}