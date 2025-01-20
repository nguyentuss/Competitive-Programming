#include <bits/stdc++.h>

using namespace std;

int n , k;
string s;
vector <int> POW(32);

void calc(int n , int k , int m) {
	if (n == 1) {
		if (k == 1) s += '0';
		else s += '1';
		return;
	}
	else {
		if (k % 2) {
			int temp = k / 2 + 1;
			m = 1;
			calc(n - 1 , temp , 1);	
		}
		else {
			int temp = k / 2;
			m = 0;
			calc(n - 1 , temp , 0);
		}
		int c;
		if (k % 2) 	c = k / 2 + 1;
		else c = k / 2;
		if (m == 1) {
			if (c % 2) s += '0';
			else s += '1';	
		}
		else {
			if (c % 2) s += '1';
			else s += '0';
		}
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	freopen("inp.inp","r",stdin);
	freopen("out.out","w",stdout);

	POW[0] = 1;
	for (int i = 1 ; i <= 30 ; i ++) {
		POW[i] = POW[i - 1]*2;
	}

	int t; cin >> t;
	while (t --) {
		s.clear();
		cin >> n >> k;
		k ++;
		calc(n , k , -1);
		int ans = 0;
		int count = 0;
		for (int i = (int) s.size() - 1 ; i >= 0 ; i --) {
			ans += (s[i] - '0')*POW[count];
			count ++;
		}
		cout << ans << endl;
	}

	return 0;
}