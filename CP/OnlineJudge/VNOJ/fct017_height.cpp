#include <bits/stdc++.h>

using namespace std;

#define ii pair<int ,int>
#define f first
#define s second

map<int ,int> m;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	vector<ii> v;
	for (int i = 0 ; i < n ;i++) {
		int x; cin >> x;
		v.push_back(ii(x , i));
	}
	sort(v.begin() , v.end());
	vector <ii> tmp;
	for (int i = 0 ; i < n ; i++) {
		tmp.push_back(ii(v[i].s , i - m[v[i].f]));
		m[v[i].f]++;
	}
	sort(tmp.begin() , tmp.end());
	for (auto e : tmp) cout << e.s << " ";
	return 0;
}