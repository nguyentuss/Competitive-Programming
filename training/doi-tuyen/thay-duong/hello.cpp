#include <bits/stdc++.h>

using namespace std;

string a;
vector <int> v[4];

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("hello.inp","r",stdin);
	freopen("hello.out","w",stdout);
	cin >> a;
	for (int i = 0 ; i < (int) a.size() ; i++) {
		if (a[i] == 'h') v[0].push_back(i);
		if (a[i] == 'e') v[1].push_back(i);
		if (a[i] == 'l') v[2].push_back(i);
		if (a[i] == 'o') v[3].push_back(i);
	}	
	for (int ch1 = 0 ; ch1 < (int) v[0].size() ; ch1++) {
		for (int ch2 = 0 ; ch2 < (int) v[1].size() ; ch2++) {
			for (int i = 0 ; i < (int) v[2].size() ; i++) {
				int tmp1 = v[2][i] , tmp2 = v[2][i + 1];
				for (int ch3 = 0 ; ch3 < (int) v[3].size() ; ch3++) {
					if (v[0][ch1] < v[1][ch2] && v[1][ch2] < tmp1 && tmp1 < tmp2 && tmp2 < v[3][ch3]) {
						cout << "YES";
						return 0;
					}
				}
			}
		}
	}
	cout << "NO";


	return 0;
}