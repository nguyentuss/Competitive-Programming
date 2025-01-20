#include <bits/stdc++.h>

using namespace std;

set<int> s;

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);

	int n , x; cin >> n;
	for (int i = 0 ; i < n; i++) {
		cin >> x;
		s.insert(x);
	}
	if ((int) s.size() == n) cout << -1;
	else cout << n - 1;
 
	return 0;
}