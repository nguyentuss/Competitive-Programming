#include <bits/stdc++.h>

using namespace std;
#define int long long

string s , a , X;
int len;
bool C[1000];
vector <string> v;

void backtr(int i) {
	for (int j = 0 ; j < len ; j++) {
		if (!C[j]) {
			C[j] = true;
			X[i] = a[j];
			if (i == len - 1) {
				v.push_back(X);
			} 
			else {
				backtr(i + 1);
			}
			C[j] = false;
		}
	}
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("hoanvi.inp","r",stdin);
	//freopen("hoanvi.out","w",stdout);
	cin >> s;
	len = s.size();
	a = s;
	sort(a.begin() , a.end());
	X = a;
	backtr(0);
	for (int i = 0 ; i < v.size() ; i++) {
		if (v[i] == s) {
			cout << i + 1;
			return 0;
		}
	}
	return 0;	
}