#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("coins.inp","r",stdin);
	freopen("coins.out","w",stdout);
	cin >> n;
	for (int i = 1 ; i * i <= n ; i++) {
		if (!(n % i)) {
			if (i == n / i) 
				v.push_back(i);
			else {
				v.push_back(i);
				v.push_back(n / i);
			}
		}
	}
	v.push_back(n);
	sort(v.begin() , v.end() , greater<int>());
	cout << v.size() << '\n';
	for (auto e : v) cout << e << " ";
	return 0;
}