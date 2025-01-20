#include <bits/stdc++.h>

using namespace std;

vector <long long> v;

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	int n , k , x ; cin >> n >> k;
	for (int i = 0 ; i < n; i ++) {
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin() , v.end() , greater<int>());


	long long ans = v[0] , before = v[0];
	for (int i = 1 ; i < n; i++) {
		if (v[i] + k <= before) {
			before = v[i];
			ans += v[i];
		}
	}

	cout << ans;


	return 0;
}