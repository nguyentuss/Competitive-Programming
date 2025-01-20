#include <bits/stdc++.h>

using namespace std;

char A[107][107];
int f[107][107][27];

int calc(int a , int b , int c , int d , int z) {
	return f[c][d][z] + f[a - 1][b - 1][z] - f[c][b - 1][z] - f[a - 1][d][z];
}

int cnt(int a , int b , int c , int d) {
	int diff = 0;
	for (int z = 0 ; z < 26 ; z++) {
		if (calc(a , b , c , d , z)) diff++;
	}
	return diff;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	cout.tie(NULL); 
	int n , m , k; cin >> n >> m >> k;
	for (int i = 1 ; i <= n ; i ++) {
		for (int j = 1 ; j <= m ; j ++) {
			cin >> A[i][j];
		}
	}

	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= m ; j++) {
			for (int z = 0 ; z < 26 ; z++) {
				f[i][j][z] = f[i - 1][j][z] + f[i][j - 1][z] - f[i - 1][j - 1][z] + (A[i][j] == z + 'A');
			}
		}
	}
	int ans = 0;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= m ; j++) {
			int l = n + 1 , r = n + 1;
			for (int h = j ; h <= m ; h++) {
				while (l - 1 >= i && cnt(i , j , l - 1 , h) >= k) l--;
				while (r - 1 >= i && cnt(i , j , r - 1 , h) > k) r--;
				ans += r - l; 
			}
		}
	}
	cout << ans;
	return 0;
}