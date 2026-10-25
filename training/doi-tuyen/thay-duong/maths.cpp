#include <bits/stdc++.h>

using namespace std;

int main(){ 
	ios::sync_with_stdio(0);cin.tie(NULL);
	cout.tie(NULL);
	freopen("maths.inp","r",stdin);
	freopen("maths.out","w",stdout);
	string s; cin >> s;
	//cout << s;
	vector <char> v;
	for (int i = 0 ; i < (int) s.size() ; i++) {
		if ('1' <= s[i] && s[i] <= '3') {
			v.push_back(s[i]);
		}
	}
	sort(v.begin() , v.end());
	for (int i = 0 ; i < v.size() ; i ++) {
		cout << v[i];
		if (i != v.size() - 1) cout << "+";
	}

	return 0;
}