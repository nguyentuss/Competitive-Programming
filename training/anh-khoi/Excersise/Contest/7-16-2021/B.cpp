#include <bits/stdc++.h>

using namespace std;

int n;
bool check(vector<int> a , vector <int> b) {
	for (int i = 0 ; i < a.size() ; i++) {
		if (a[i] != b[i]) return true;
	}
	return false;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cin >> n;

	map<int , vector <int>> m;
	for (int i = 0 ; i < n ; i ++) {
		int x , y;
		cin >> x >> y;
		m[y].push_back(x);
	}
	for (auto it : m) {
		vector <int> a , b;
		a = b = it.second;
		sort(a.begin() , a.end());
		if (check(a , b)) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";

	return 0;
}