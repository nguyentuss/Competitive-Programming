#include <bits/stdc++.h>

using namespace std;

vector <int> v;
vector <int> change;
map<int , bool> m;
int x , n;

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	int t; cin >> t;
	while (t --) {
		v.clear();
		m.clear();
		change.clear();
		cin >> n;
		for (int i = 0 ; i < n ; i++) {
			cin >> x;
			v.push_back(x);
		}
		for (int i = 0 ; i < n ; i++) {
			if (m[i] == false) {
				change.push_back(v[i]);
				m[i] = true;
			}
			if (m[n - 1 - i] == false) {
				change.push_back(v[n - 1 - i]);
				m[n - 1 - i] = true;
			}
		}
		for (int i = 0 ; i < (int) change.size() ; i++) 
			cout << change[i] << " ";
		cout << '\n';
	}
	return 0;
}