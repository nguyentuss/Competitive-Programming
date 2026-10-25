#include <bits/stdc++.h>

using namespace std;

string a , b;
int n , m , q;
set<int> s;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("test.inp","r",stdin);
	freopen("test.out","w",stdout);
	cin >> n >> q;
	cin >> a >> b;
	a = '0' + a;
	b = '0' + b;
	for (int i = 1 ; i <= n ;i++) {
		if (b[i] == '1' && a[i] == '0') {
			break;
		}
		else if ((b[i] == '0' && a[i] == '0') || (b[i] == '1' && a[i] == '1')) continue;
		else {
			s.insert(i);
		}	
	}
	bool found = false;
	for (int i = 0 ; i < q ; i++) {
		int x; cin >> x;
		if (s.empty()) found = true;
		if (found) {
			cout << "YES" << '\n';
			continue;
		}
		auto tmp = s.find(x);
		if (tmp == s.end()) cout << "NO" << '\n';
		else {
			auto cmp = s.upper_bound(x);
			//cout << x << " " << *cmp << '\n';
			/*if (*cmp == (x + 1)) {
				s.erase(*tmp);
			}
			else {
				cmp = s.lower_bound(x);
				while (cmp != s.end()) {
					s.erase(*cmp);
					cmp = s.lower_bound(*cmp);
				}
			}*/
			s.erase(*tmp);
			if (s.empty()) {
				cout << "YES" << '\n';
			}
			else cout << "NO" << '\n';
		}
		for (auto x : s) {
			cout << x << " ";
		}
		cout << '\n';
	}


	return 0;
}