#include <iostream>
#include <fstream>
using namespace std;
int n, d=0;
char X[45];
string S;
int T[300];
int best = 1000000;
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
	best = T[n];
	d += 1;
	for (int i = 1; i <= n; i++) {
		S += X[i];
	}
}

void nghiem(int i) {
	for (int j = 'A'; j <= 'C'; j++) {
		if (check(i, j)) {
			X[i] = j;
			if (j == 'C') T[i] = T[i - 1] + 1;
			else T[i] = T[i -1];
			if (T[i] + (n - i)/4 < best)  
			if (i == n) in();
			else nghiem(i+1);
		}
	}
}

int main() {
	//freopen("tudep3.inp","r",stdin);
	//freopen("tudep3.out","w",stdout);
	cin >> n;
	nghiem(1);
	T[0] = 0;
	cout << d << endl;
	cout << S;119
	return 0;
}