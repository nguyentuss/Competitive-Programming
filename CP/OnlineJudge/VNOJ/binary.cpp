#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e2)

int C[MAX_N][MAX_N];
int n , k;
int get(int n , int k) {
	return ((n >> (k - 1))&1);
}

void calc() {
	for (int i = 0 ; i <= 34 ; i++) { 
		C[i][0] = 1;
		C[i][i] = 1;
	}

	for (int i = 1 ; i <= 34; i++) {
		for (int j = 1 ; j <= 34 ; j ++) {
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];	
		}
	}
	return;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.inp","r",stdin);
	//freopen("test.out","w",stdout);
	calc();

	while (cin >> n >> k) {
		int res = 0 , pos = 0 , counted = 0;
		bool checked = false;
		vector <int> num(MAX_N , 0);
		if (k == 1) res++;
		for (int i = 32; i >= 1 ;i--) {
			if (!get(n , i)) {
				num[i] = 0;
				if (checked) counted ++;
				continue;
			}
			num[i] = 1;
			if (!checked) {
				pos = i;
				checked = true; 
			}
		}
		if (k == counted) res ++;
		counted = 0;
		for (int i = pos - 1 ; i >= 1 ; i--) {
			if (num[i] == 0) {
				counted ++;
				continue;
			}
			int tmp = k - counted - 1;
			if (tmp > i - 1 || tmp < 0) continue;
			res += C[i - 1][tmp];
		}
		for (int i = pos - 1 ; i >= k + 1 ; i--) {
			if (k > i - 1) continue;
			res += C[i - 1][k];
		}
		cout << res << '\n';
	}

	return 0;
}