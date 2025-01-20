#include <bits/stdc++.h>

using namespace std;

int x , n;
vector <int> v;

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);

	int t; cin >> t;
	for (int test = 1 ; test <= t ; test ++) {
		cin >> n;
		v.clear();
		for (int i = 0 ; i < n ; i++) {
			cin >> x;
			v.push_back(x);
		}
		int ans = 0;
		for (int i = 1 ; i < (int) v.size() - 1 ; i++) {
			if (v[i] > v[i - 1] && v[i] > v[i + 1]) ans ++ ;
		}
		cout << "Case #" << test << ": " << ans << '\n';
	}

	return 0;
}