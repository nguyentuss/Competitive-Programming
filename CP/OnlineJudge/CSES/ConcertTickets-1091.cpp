#include <bits/stdc++.h>

using namespace std;

#define ii pair<int ,int>
#define f first
#define s second

int n , m;
multiset<int , greater<int>> s;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0 ; i < n ;i++) {
		int x; cin >> x;
		s.insert(x);
	}
	while (m--) {
		int x; cin >> x;
		auto e = s.lower_bound(x);
		if (e == s.end()) cout << -1 << '\n';
		else {
			cout << *e << '\n';
			s.erase(e);
		}
	}
	return 0;
}