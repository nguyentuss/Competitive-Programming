#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")

using namespace std;

int n , x;
vector <int> v;

int main(){
	freopen("daytang.inp","r",stdin);
	freopen("daytang.out","w",stdout);
	cin >> n;
	for (int i = 0 ; i < n ; i++) {
		cin >> x;
		v.push_back(x);
	}
	int l = 0 , r;
	int ans = -1;
	for (int i = 1 ; i < n ; i++) {
		if (v[i] < v[i - 1]) {
			ans = max(ans , i - l);
			l = i;
		} 
	}
	cout << ans;
	return 0;
}
