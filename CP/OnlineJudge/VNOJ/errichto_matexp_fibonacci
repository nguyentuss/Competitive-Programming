#include <bits/stdc++.h>

using namespace std;

#define MOD (int) (111539786)
#define int long long

struct matrix {
	int row , col;
	vector<vector<int>> ngarcute;
	matrix(int _row , int _col) {
		row = _row;
		col = _col;
		ngarcute.resize(row);
		for (int i = 0 ; i < row ; i++) {
			ngarcute[i].resize(col , 0);
		}
	}
	matrix operator * (const matrix &other) {
		matrix ret(row , other.col);
		for (int i = 0 ; i < row ; i++) {
			for (int j = 0 ; j < other.col ; j++) {
				for (int k = 0 ; k < col ; k++) {
					(ret.ngarcute[i][j] += (ngarcute[i][k]*other.ngarcute[k][j]) % MOD)%=MOD;
				}
			}
		}
		return ret;
	}
};

matrix POW(const matrix &M  , int N) {
	if (N == 1) return M;
	matrix ret = POW(M , N / 2);
	ret = ret*ret;
	if (N % 2 == 1) ret = ret*M;
	return ret;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.inp","r",stdin);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		if (n == 1) {
			cout << 1 << '\n';
			continue;
		}
		matrix base(2 , 2);
		base.ngarcute[0][0] = 0;
		base.ngarcute[0][1] = 1;
		base.ngarcute[1][0] = 1;
		base.ngarcute[1][1] = 1;
		matrix ans = POW(base , n - 1);
		matrix M(2 , 1);
		M.ngarcute[0][0] = 1;
		M.ngarcute[1][0] = 1;
		ans = ans*M;
		cout << ans.ngarcute[1][0] << '\n';
	}

	return 0;
}