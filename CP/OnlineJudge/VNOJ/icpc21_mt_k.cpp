#include <bits/stdc++.h>

using namespace std;

#define mod (int) (1e9 + 7)
#define MAX_N (int) (107)

int n , m , t;
char a[MAX_N][MAX_N];
int dx[] = {0 , 0 , 1 , -1};
int dy[] = {1 , -1 , 0 , 0};

struct matrix {
	int row , col;
	vector<vector<int>> ngar;
	matrix(int _row , int _col) {
		row = _row;
		col = _col;
		ngar.resize(row);
		for (int i = 0 ; i < row ; i++) {
			ngar[i].resize(col , 0);
		}
	}

	matrix operator *(const matrix &other) {
		matrix ret(row , other.col);
		for (int i = 0 ; i < row ; i++) {
			for (int j = 0 ; j < other.col ; j++) {
				for (int k = 0 ; k < col ; k++) {
					ret.ngar[i][j] += ngar[i][k]*other.ngar[k][j];
				}
			}
		}
		return ret;
	}
};

matrix POW(const matrix &M , int N) {
	if (N == 1) return M;
	matrix ret = POW(M , N/2);
	ret = ret*ret;
	if (N % 2) ret = ret*M;
	return ret;
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("test.inp","r",stdin);
	cin >> n >> m >> t;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= m ; j++) {
			cin >> a[i][j];
		}
	}
	matrix base(n*m , n*m);
	int row = 0 , col = 0;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= m ; j++) {
			col = 0;
			for (int k = 1 ; k <= n ; k ++) {
				for (int h = 1 ; h <= m ; h++) {
					int tmp = 0;
					if (a[k][h] == '#') base.ngar[row][col] = 0;
					else if (a[k][h] == 'R' && h + 1 <= m && k == i && h + 1 == j) base.ngar[row][col] = 1;
					else if (a[k][h] == 'D' && k + 1 <= n && k + 1 == i && h == j) base.ngar[row][col] = 1;
					else if (a[k][h] == 'L' && h - 1 > 0 && k == i && h - 1 == j) base.ngar[row][col] = 1;
					else if (a[k][h] == 'U' && k - 1 > 0 && k - 1 == i && h == j) base.ngar[row][col] = 1;
					else if (a[k][h] == '+') {
						for (int tm = 0 ; tm < 4 ; tm++) {
							int x = k + dx[tm];
							int y = h + dy[tm];
							if (x <= 0 || x > n || y <= 0 || y > m) continue;
							if (x == i && y == j) {
							 	base.ngar[row][col] = 1;
								break;
							}
						}	
					}
					else base.ngar[row][col] = 0;
					col++;
				}
			}
			row++;
		}
	}
	for (int i = 0 ; i < n*m ; i++) {
		for (int j = 0 ; j < n*m ; j++) {
			cout << base.ngar[i][j] << " ";
		}
		cout << '\n';
	}
	matrix ans = base*base;
	matrix M(n*m , 1);
	col = 0;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= m ; j++) {
			M.ngar[col][0] = (a[i][j] == '#' ? 0 : 1);
			col++;
		}
	}
	//for (int i = 0 ; i < n*m ; i++) {
	//	cout << M.ngar[0][i] << " ";
	//}
	ans = ans*M;
	
	cout << 1;
	return 0;
}