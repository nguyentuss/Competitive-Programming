#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int n ; cin >> n;
	for (int i = 1 ; i <= n ; i ++) {
		for (int j = 1 ; j <= 2*n + 1 ; j ++) {
			if (j <= n) {
				if (i != n) {
					if (j == 1 || j == n) cout << "*"; 
					else cout << " ";
				}
				else cout << "*";
			} 
			if (j == n + 1) cout << " ";
			if (j > n + 1) {
				if (i != 1) {
					if (j == n + 2 || j == 2*n + 1) cout << "*";
					else cout << " "; 
				}
				else cout << "*";
			}

		}
		cout << '\n';
	}


	return 0;
}