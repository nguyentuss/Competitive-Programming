#include <bits/stdc++.h>

using namespace std;

char a[55][55];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 1 ; i <= n ; i++) {
			for (int j = 1 ; j <= n ; j ++) {
				a[i][j] = ' ';
			}
		}
		vector<int> v;
		string s; cin >> s;
		s = '0' + s;
		int numberoftype1 = 0, numberoftype2 = 0;
		for (int i = 1 ; i <= n ; i++) {
			if (s[i] == '2') {
				numberoftype2 ++;
				v.push_back(i);
			}
			else numberoftype1 ++;	
		}
		if (!v.empty()) v.push_back(v[0]);
		if (numberoftype2 == 2 || numberoftype2 == 1) cout << "NO" << '\n';
		else {
			cout << "YES" << '\n';
			bool status;
			for (int i = 1 ; i <= n ; i++) {
				status = (s[i] == '1'?1 : 0);
				for (int j = 1 ; j <= n ; j++) {
					if (i == j) {
						a[i][i] = 'X';
						continue;
					}
					if (status && s[j] == '1') 
						a[i][j] = '=';
					else if (status && s[j] == '2') {
						a[i][j] = '+';
						a[j][i] = '-';
					}
					else if (!status && s[j] == '1') {
						a[i][j] = '-';
						a[j][i] = '+';
					}
				}
			}
			if (!v.empty()) {
				for (int i = 0 ; i < v.size() - 1 ; i++) {
					a[v[i]][v[i + 1]] = '+';
					a[v[i + 1]][v[i]] = '-'; 
				}
			}
			for (int i = 1 ; i <= n ; i++) {
				for (int j = 1 ; j <= n ; j++) {
					if (a[i][j] == ' ') cout << '=';
					else cout << a[i][j];
				}
				cout << '\n';
			}
		}
	}
	return 0;
}