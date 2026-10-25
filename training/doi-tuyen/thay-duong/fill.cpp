#include <bits/stdc++.h>
using namespace std;

#define ii pair<int ,int>

string a , b , c;
ii ans;

ii check() {
	for (int i = 0 ; i < a.size() ; i++) {
		if (a[i] == '?') {
			return ii(1 , i);
		}
	}
	for (int i = 0 ; i < b.size() ; i++) {
		if (b[i] == '?') return ii(2 , i);
	}
	for (int i = 0 ; i < c.size() ; i++) {
		if (c[i] == '?') return ii(3 , i);
	}
}
int change(int x) {
	vector <int> tmp;
	while (x > 0) {
		tmp.push_back(x % 10);
		x /= 10;
	}
	reverse(tmp.begin() , tmp.end());
	return tmp[ans.second];
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("fill.inp","r",stdin);
	freopen("fill.out","w",stdout);
	cin >> a >> b >> c;
	ans = check();
	if (ans.first == 1) {
		int x , y;
		istringstream(c) >> x;
		istringstream(b) >> y;
		int rest = x - y;
		cout << change(rest);
		return 0;
	}
	else if (ans.first == 2) {
		int x , y;
		istringstream(c) >> x;
		istringstream(a) >> y;
		int rest = x - y;
		cout << change(rest);
	}
	else {
		int x , y;
		istringstream(a) >> x;
		istringstream(b) >> y;
		int rest = x + y;
		cout << change(rest);
	}

	return 0;
}