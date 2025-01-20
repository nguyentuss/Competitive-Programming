#include <bits/stdc++.h>

using namespace std;

int n , m , x;
vector <int> v;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0 ; i < n ; i++) {
		cin >> x;
		v.push_back(x);
	}

	int total = 0 , ans = 0;
	sort(v.begin() , v.end());
	for (int i = 0 ; i < n; i++) {
		total += v[i];
		if (total <= m) ans ++;
		else {
			cout << ans ;
			return 0;
		}
	}

	return 0;
}