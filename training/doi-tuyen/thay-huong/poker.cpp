#include <bits/stdc++.h>

using namespace std;

map <string , bool> P;
map <string , bool> K;
map <string , bool> H;
map <string , bool> T;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("poker.inp","r",stdin);
	freopen("poker.out","w",stdout);
	string s; cin >> s;
	int cntP = 13 , cntK = 13 , cntH = 13 , cntT = 13;
	for (int i = 0 ; i < (int) s.size() ; i++) {
		string tmp;
		tmp += s[i + 1];
		tmp += s[i + 2];
		if (s[i] == 'P' ) {
			if (P[tmp]) {
				cout << -1;
				return 0;
			}
			else P[tmp] = true , cntP --;
		}	
		if (s[i] == 'K') {
			if (K[tmp]) {
				cout << -1;
				return 0;
			}
			else K[tmp] = true , cntK --;
		}
		if (s[i] == 'H') {
			if (H[tmp]) {
				cout << -1;
				return 0;
			}
			else H[tmp] = true , cntH --;
		}
		if (s[i] == 'T') {
			if (T[tmp]){
				cout << -1;
				return 0;
			}
			else T[tmp] = true , cntT --;
		}
		i += 2;
	}
	cout << cntP << " " << cntK << " " << cntH << " " << cntT;
	return 0;
}