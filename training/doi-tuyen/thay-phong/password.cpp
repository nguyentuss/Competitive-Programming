#include <bits/stdc++.h>

using namespace std;

map<string , int> m;
map<string ,bool> mark;
string s[10007];
int n;

int checked(string a) {
	mark.clear();
	int res = 0;
	for (int l = 0 ; l < a.size() ;l++) {
		string tmp;
		for (int r = l ; r < a.size() ; r++) {
			tmp += a[r];
			if (!mark.count(tmp) && m.count(tmp)) {
				res += m[tmp];
				mark[tmp] = true;
			} 
		}
	}
	return res - 1;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	cin >> n;
	for (int i = 1 ; i <= n ;i++) {
		cin >> s[i];
		m[s[i]] ++;
	}
	for (int i = 1 ; i <= n ;i++) cout << checked(s[i]) << '\n';
	return 0;
}