#include <bits/stdc++.h>

using namespace std;

#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
					ret.ngarcute[i][j] += ngarcute[i][k]*other.ngarcute[k][j];
				}
			}
		}
		return ret;
	}
};

void sp(int &num)
{
    register int c;
    num = 0;
    for(c = getchar() ; c < 48 || c > 57 ; c = getchar());
    for(; c >= 48 && c <= 57 ; c = getchar())
        num = num * 10 + c - 48;
}

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
	int t;sp(t);
    while (t--) {
        int n; sp(n);
        matrix a(n , n);
        matrix b(n , n);
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < n ; j++) {
                sp(a.ngarcute[i][j]);
            }
        }
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < n ; j++) {
                sp(b.ngarcute[i][j]);
            }
        }
        matrix c = POW(a , 3);
        bool check = true;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < n ; j++) {
                if (c.ngarcute[i][j] != b.ngarcute[i][j]) {
                    check = false;
                }
            }
        }
        if (check) {
            cout << "YES" << '\n';
        }
        else cout << "NO" << '\n';
    }
	return 0;
}