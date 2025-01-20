#include <bits/stdc++.h>

using namespace std;

map<string , int> val;
vector<string> v;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	cout.tie(NULL);
	//freopen("inp.inp","r",stdin);
	//freopen("out.out","w",stdout);
	val["Do"] = 1 , val["Re"] = 2 , val["Mi"] = 3 , val["Fa"] = 4 , val["Son"] = 5;
	val["La"] = 6 , val["Si"] = 7;
	int t; cin >> t;
	while (t--) {
		v.clear();
		int n , m; cin >> n >> m; 
		for (int i = 0 ; i < n ;i++) {
			string s; cin >> s;
			v.push_back(s);
		}
		int cnt = 0;
		for (int i = 1 ; i < n - 1 ; i++) {
			if ((val[v[i]] > val[v[i - 1]] && val[v[i]] > val[v[i + 1]])
			|| (val[v[i]] < val[v[i - 1]] && val[v[i]] < val[v[i + 1]])) cnt++; 
		}
		cout << (cnt >= m ?"YES":"NO") << '\n';
	}
	return 0;
}