#include <bits/stdc++.h>

using namespace std;

string s1 , s2;
int a , b;


int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("AC2.inp","r",stdin);
	//freopen("AC2.out","w",stdout);
	int t; cin >> t;
	while (t--) {
		cin >> s1 >> s2;
		cin >> a >> b;
		int cnt1 = 0 , cnt2 = 0 , minimum = min(a , b);
		int x;
		bool check = false;
		for (int i = 0 ; i < a + b ; i++) {
			string tmp , tmp1;
			cin >> tmp >> tmp1;
			if (tmp == s1) cnt1++ ;
			else cnt2 ++;
			if (cnt1 > minimum && !check) {
				cout << s1 << " " << tmp1 << '\n';
				check = true;
			}
			else if (cnt2 > minimum && !check){
				cout << s2 << " " << tmp1 << '\n';
				check = true;
			} 
		}
	}
	return 0;
}