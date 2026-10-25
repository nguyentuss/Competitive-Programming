#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
int n, d=0;
char X[111000];

bool check(int l, char a) {
	string x;
	x += ' ';
	X[l] = a;
	for (int i = 1; i <= l; i++) {
		x += X[i];
	}
	for (int k = 1; k <= l/2; k++) {
		if (x.substr(l-k+1, k) == x.substr(l-2*k+1, k)) return false;
	}
	return true;
}

void in() {
	for (int i = 1 ; i <= n ; i++) cout << X[i];
	exit(0);
}

void nghiem(int i) {
	for (int j = 'A'; j <= 'C'; j++) {
		if (check(i, j)) {
			X[i] = j;
			if (i == n) in();
			else nghiem(i+1);
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	freopen("tudep2.inp","r",stdin);
	freopen("tudep2.out","w",stdout);
	cin >> n;
	nghiem(1);
	return 0;
}