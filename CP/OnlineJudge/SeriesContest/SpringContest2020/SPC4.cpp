#include <bits/stdc++.h>

using namespace std;

int test , n , k , t , x;
int f[40][40][40];
vector <int> v;
vector <int> sum(40);

// f[i][a][b] la gia tri lon nha khi choi toi i la bai va nguoi hien tai dang co 
// a la' va doi thu dang co b la

void init() {
	for (int i = 0 ; i <= n ; i++) {
		sum[i] = 0;
		for (int a = 0 ; a <= max(k , t) ; a++) 
			for (int b = 0 ; b <= max(k , t) ; b++) {
				f[i][a][b] = 0;
			}
	}
	f[0][k][t] = 0;
	v.clear();
	v.push_back(0);
	return;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);

	cin >> test; 
	while (test--) {
		cin >> n >> k >> t;
		init();
		for (int i = 1 ; i <= n ; i++) {
			cin >> x;
			v.push_back(x);
			sum[i] = sum[i - 1] + x;
		}
		for (int i = 1; i <= n ; i++) {
			for (int a = 0 ; a <= max(k , t) ; a ++) {
				for (int b = 0 ; b <= max(k , t) ; b ++) {
					for (int x = 0 ; x <= min(a , i - 1) ; x++) {
						f[i][a][b] = max(f[i][a][b] , sum[i] - f[i - x - 1][b][a - x]);
					}
				}
			}
		}
		if (sum[n] - f[n][k][t] == f[n][k][t]) cout << "DRAW" << '\n';
		else if (sum[n] - f[n][k][t] > f[n][k][t]) cout << "LOSE" << '\n';
		else cout << "WIN" << '\n';
	}

	return 0;
}