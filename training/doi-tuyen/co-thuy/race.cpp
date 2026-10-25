#include <bits/stdc++.h>

using namespace std;

#define inf (1e9 + 7)

int f[2*307][307][307];
int v[307][307];
int n;

int find_pos(int x , int k) {
	return (k - x + 2);
}

void calc(int i , int j , int x , int y , int ni , int nj , int nx , int ny , int k) {
	if (ni <= n && nj <= n && nx <= n && ny <= n) {
		if (ni == nx && nj == ny) {
			f[k][ni][nx] = max(f[k][ni][nx] , f[k - 1][i][x] + v[ni][nj]);
		}
		else
			f[k][ni][nx] = max(f[k][ni][nx] , f[k - 1][i][x] + v[ni][nj] + v[nx][ny]);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("race.inp","r",stdin);
	freopen("race.out","w",stdout);
	cin >> n;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= n ; j++) {
			cin >> v[i][j];
		}
	}
	for (int k = 0 ; k <= 2*n - 2 ; k++) {
		for (int a = 1 ; a <= n ; a++) {
			for (int b = 1 ; b <= n ; b++) {
				f[k][a][b] = -inf;
			}
		}
	}
	f[0][1][1] = v[1][1];
	for (int k = 0 ; k <= 2*n - 2 ; k++) {
		for (int a = 1 ; a <= n ; a++) {
			for (int b = 1 ; b <= n ; b++) {
				if (f[k][a][b] == -inf) continue;
				int c = find_pos(a , k);
				int d = find_pos(b , k);
				calc(a , c , b , d , a + 1 , c , b + 1 , d , k + 1);
				calc(a , c , b , d , a + 1 , c , b , d + 1 , k + 1);
				calc(a , c , b , d , a , c + 1 , b + 1 , d , k + 1);
				calc(a , c , b , d , a , c + 1 , b , d + 1 , k + 1);
			}
		}
	}
	cout << f[2*n - 2][n][n];
	return 0;
}