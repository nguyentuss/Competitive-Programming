#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <int> v;
		int total = 0 ,x;
		for (int i = 0 ; i < n ; i++) {
			cin >> x;
			total += x;
			v.push_back(x);
		}
		if (total % n != 0) cout << -1 << '\n';
		else {
			int divide = total / n , ans =0 ;
			for (int i = 0 ; i < n ;i++)
				if (v[i] > divide) ans ++;
			cout << ans << '\n';
		}

	}
	return 0;
}