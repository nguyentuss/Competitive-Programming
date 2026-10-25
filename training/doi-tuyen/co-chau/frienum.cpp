#include <iostream>
#include <fstream>
#include <math.h>
#include <algorithm>
using namespace std;
int l, r, C[1000005]={0}, ans=0;

int ucln(int a, int b) {
	int r = a%b;
	while (r != 0) {
		a = b;
		b = r;
		r = a%b;
	}
	return b;
}

int nguoc(int a) {
	int t = 0;
	while (a > 0) {
		t = t*10+a%10;
		a /= 10;
	}
	return t;
}

int main() {
	freopen("frienum.inp","r",stdin);
	freopen("frienum.out","w",stdout);
	cin >> l >> r;
	for (int i = l; i <= r; i++) {
		if (C[i]==0) { 
			int t = nguoc(i);
			if (ucln(i, t) == 1) {
				C[i] = 1;
				ans += 1;
				if (t>=l && t<=r && C[t]==0) {
					ans += 1;
					C[t] = 1;
				}
			}
		}
	}
	cout << ans;
	return 0;
}