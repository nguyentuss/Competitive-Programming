#include <bits/stdc++.h>

using namespace std;


set <pair<int ,int>> s;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("abc.inp","r",stdin);
	freopen("abc.out","w",stdout);
	int ask;
	while (cin >> ask) {
		if (ask == 0) break;
		else if (ask == 1) {
			int k , p; cin >> k >> p;
			s.insert(make_pair(p , k));
		}
		else if (ask == 2) {
			if (s.empty()) cout << 0 << '\n';
			else {
				auto x = s.rbegin();
				cout << x->second << '\n';
				s.erase(*x);
			}
		}
		else if (ask == 3) {
			if (s.empty()) cout << 0 << '\n';
			else {
				auto x = s.begin();
				cout << x->second << '\n';
				s.erase(*x);	
			}
		}
	}

	return 0;
}