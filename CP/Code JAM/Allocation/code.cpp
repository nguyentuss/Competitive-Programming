#include <bits/stdc++.h>

using namespace std;

int main(){ 
	ios::sync_with_stdio(0); cin.tie(NULL);

	int t ;cin >> t;
	for (int test = 1 ; test <= t ; test ++) {
		int n , b;
		cin >> n >> b;
		int x;
		vector <int> v;
		for (int i = 0 ; i < n ; i ++) {
			cin >> x;
			v.push_back(x);
		}
		sort(v.begin() , v.end());
		int ans = 0;
		int total = 0;
		for (int i = 0 ; i < n; i++) {
			total += v[i];
			if (total <= b) ans ++;
			else {
				cout << "Case #" << test << ": " << ans << '\n';
				break;
			}
		}

	}

	return 0;
}