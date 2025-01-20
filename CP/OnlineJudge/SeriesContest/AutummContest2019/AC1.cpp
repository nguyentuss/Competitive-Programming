#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int len = 20;

int A , B , C;
ll f[22][2][2][2];

string changetobit(int x) {
	string s = ""; 
  	for (int i = len - 1; i >= 0; i--) {
	    if ((x & (1 << i)) > 0) {
	      s += "1"; 
	    }
	    else {
	      s += "0";
	    }
  	}
  return s; 
}

ll dynamicProgramming() {
	string Bi_A = changetobit(A);
	string Bi_B = changetobit(B);
	string Bi_C = changetobit(C);
	for (int i = 0 ; i < 22 ; i++) {
		for (int a = 0 ; a <= 1 ; a++) {
			for (int b = 0 ; b <= 1 ; b++) {
				for (int c = 0 ; c <= 1 ; c++) {
					f[i][a][b][c] = 0;
				}
			}
		}
	}
	f[0][1][1][1] = 1LL;
	for (int i = 0 ; i <= len ; i++) {
		for (int a = 0 ; a <= 1 ; a++) {
			for (int b = 0 ; b <= 1 ; b++) {
				for (int c = 0 ; c <= 1 ; c++) {
					if (f[i][a][b][c] == 0) continue;
					ll val = f[i][a][b][c];
					for (int x = 0 ; x <= (!a?1:Bi_A[i] - '0') ; x++) {
						for (int y = 0 ; y <= (!b?1:Bi_B[i] - '0') ; y++) {
							if (x > Bi_A[i] || y > Bi_B[i]) continue;
							int z = x ^ y;
							if (c == 1 && z > Bi_C[i] - '0') continue;
							int newa = (a && x == Bi_A[i] - '0');
							int newb = (b && y == Bi_B[i] - '0');
							int newc = (c && z == Bi_C[i] - '0');
							f[i + 1][newa][newb][newc] += val;
						}
					}

				}
			}
		}
	}
	ll ans = 0;
	for (int a = 0 ; a <= 1 ; a++) {
		for (int b = 0 ; b <= 1 ; b++) {
			for (int c = 0 ; c <= 1 ; c++) {
				ans += f[len][a][b][c];
			}
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int t ; cin >> t;
	while (t--) {
		cin >> A >> B >> C;
		cout << dynamicProgramming() << '\n';
	}
	return 0;
}