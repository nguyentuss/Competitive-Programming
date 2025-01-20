#include <bits/stdc++.h>

using namespace std;

int n , x;
map<int ,int> m;
map<int ,int> pos;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> x;
	for (int i = 0 ; i < n ;i++) {
		int tmp; cin >> tmp;
		m[tmp] ++;
		pos[tmp] = i + 1;
		v.push_back(tmp);
	}
	for (int i = 0 ; i < n ;i++) {
		if (x - v[i] == v[i] && m[v[i]] > 1) {
			cout << i + 1 << " " << pos[v[i]];
			return 0;
		} 
		else if (m[x - v[i]] && x - v[i] != v[i]) {
			cout << pos[v[i]] << " " << pos[x - v[i]];
			return 0;
		}
	}
	cout << "IMPOSSIBLE";
	return 0;
}