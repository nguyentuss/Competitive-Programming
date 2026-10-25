#include <iostream>
#include <fstream>
using namespace std;
int n, d=0;
char X[45];
string S[1000005];

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
	d += 1;
	for (int i = 1; i <= n; i++) {
		S[d] += X[i];
	}
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
	freopen("tudep1.inp","r",stdin);
	freopen("tudep1.out","w",stdout);
	cin >> n;
	nghiem(1);
	cout << d << endl;
	for (int i = 1; i <= d; i++) {
		cout << S[i] << endl;
	}
	return 0;
}