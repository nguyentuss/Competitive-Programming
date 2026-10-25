#include <bits/stdc++.h>

using namespace std;

vector <int> v;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		v.clear();
		int n ; cin >> n;
		for (int i = 2 ; i * i <= n ; i++) {
			if (n % i == 0) {
				while (n % i == 0) {
					v.push_back(i);
					n /= i;
				}
			}
		}
	
		if (n != 1) {
			v.push_back(n);
		}
		for (int i = 0 ; i < v.size() ; i++) {
			cout << v[i];
			if (i != v.size() - 1) cout << '*';
		}
		cout << '\n';
	}
	return 0;
}