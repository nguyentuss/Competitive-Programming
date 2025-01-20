#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

#define boost ios::sync_with_stdio(0);cin.tie(NULL);

int main() {
	boost;

	int t ; cin >> t;
	while (t --) {
		set<int> s;
		int n , x; cin >> n;
		for (int i = 1 ; i <= n; i++) {
			cin >> x;
			s.insert(x);
		}
		int k;
		cin >> k;
		if (n - (int) s.size() >= k) cout << (int) s.size() << endl;
		else cout << (int) s.size() - (k - (n - (int) s.size())) << endl; 
	}
	return 0;
}