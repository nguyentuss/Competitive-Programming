#include <bits/stdc++.h>

using namespace std;

int n , k , x , counted;
vector <int> v;

bool check(int count) {
	return (count == k);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	int t; cin >> t;
	for (int test = 1 ; test <= t ; test ++) {
		cin >> n >> k;
		v.clear();
		for (int i = 0 ; i < n ; i++) {
			cin >> x;
			v.push_back(x);
		}
		int ans = 0 ;
		counted = 0;
		reverse(v.begin() , v.end());
		for (int i = 0 ; i < n ; i++) {
			if (v[i] == v[i + 1] - 1 && v[i] == counted + 1) {
				counted ++ ;
				if (check(counted)) {
					ans ++;
					counted = 0;
				}
			} 
			else {
				counted ++;
				if (check(counted)) {
					ans ++ ;
					counted = 0;
				}
				counted = 0;
			}
		}
		cout << "Case #" << test << ": " << ans << '\n';
	}
	return 0;
}