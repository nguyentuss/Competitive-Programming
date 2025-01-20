#include <bits/stdc++.h>

using namespace std;

char a[20][20];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int t ; cin >> t;
	while (t--) {
		int n , D; cin >> D >> n;
		D = 15; cout << D << " " << D;
		for (int i = 1 ; i <= D ; i++) {
			for (int j = 1 ; j <= D ; j++) {
				if (j % 4 == 1) a[i][j] = 'A';
				else a[i][j] = 'C';
			}
		}
		for (int i = 2 ; i < D ; i++) {
			for (int j = 2 ; j <= D ; j += 2) {
				if (n >= 3) {
					a[i][j] = 'B';
					n -= 3;
				}
			}
		}
		for (int j = 2 ; j <= D ; j += 2) {
			if (n > 0) {
				a[1][j] = 'B';
				n--;
			}
			if (n > 0) {
				a[D][j] = 'B';
				n --;
			}
		}
		for (int i = 1 ; i <= D ; i++) {
			for (int j = 1 ; j <= D ; j++) {
				cout << a[i][j];
			}
			cout << '\n';
		}
	}
	return 0;
}