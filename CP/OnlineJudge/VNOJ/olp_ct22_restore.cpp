//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
const int inf = 1e9;
const int mod = 1e9 + 7;
const int N = 5e3 + 7;

//int f[N][107];

/**
 * Author: Tomatoes
 * Date: 2023-07-29
 * License: CC0
 * Source: Tomatoes
 * Description: Matrix operations (not necessarily square mats).
 * Matrix pow can only be on square matrices.
 * Status: tested on yosupo judge
 */
#pragma once

template<class T> struct Matrix {
	int n, m; vector<vector<T>> d;
	Matrix(int n, int m) : n(n), m(m), d(n, vector<T>(m )) {}
	Matrix operator*(const Matrix& o) const {
		assert(m == o.n); Matrix a(n, o.m);
		rep(i,0,n) rep(k,0,m) rep(j,0,o.m) // order matters
			(a.d[i][j] += (d[i][k] * o.d[k][j])%mod)%=mod;
		return a;
	}
	vector<T> operator*(const vector<T>& vec) const {
		assert(m == sz(vec)); vector<T> a(n);
		rep(i,0,n) rep(j,0,m) (a[i] += (d[i][j] * vec[j])%mod)%=mod;
		return a;
	}
	Matrix operator^(ll e) const {
		assert(e >= 0 && n == m); Matrix a(n, n), b(*this);
		rep(i,0,n) a.d[i][i] = 1;
		for (; e; e >>= 1, b = b * b) if (e & 1) a = a * b;
		return a;
	}
};



void solve() {
    int n , k; cin >> n >> k;
    /*      SUBTASK 1
        f[0][0] = 1;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < k ; j++) {
                if (f[i][j] != 0) {
                    f[i + 1][(j + 1)%k] = (f[i + 1][(j + 1)%k] + (f[i][j]*3ll)%mod)%mod;
                    f[i + 1][(j + 2)%k] = (f[i + 1][(j + 2)%k] + (f[i][j]*3ll)%mod)%mod;
                    f[i + 1][j] = (f[i + 1][j] + f[i][j])%mod;
                }
            }
        }
        cout << (f[n][0] - 1 + mod)%mod;
    */
   /* 
    1 0 0 .. 1 1
    1 1 0 .. 0 1
    1 1 1 .. 0 0
    .
    . 
    0 0 .. 1 1 1
   */
    Matrix<int> M(k , k);
    int cnt = 0;
    for (int i = 0 ; i < k ; i++) {
        int x = k - 2 + (cnt++);
        M.d[i][x%k] = M.d[i][(x + 1)%k] = 3;
        M.d[i][(x+2)%k] = 1;
    }
    Matrix<int> B(k , 1); 
    B.d[0][0] = 1; 
    for (int i = 1 ; i < k ; i++) B.d[i][0] = 0;
    M = M^n;
    M = M * B;
    cout << M.d[0][0] - 1; 
    // for (int i = 0 ; i < k ; i++) {
    //     for (int j = 0 ; j < k ; j++) {
    //         cout << M.d[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test; 
    test = 1;
    //cin >> test;
    while (test--) {
        solve();
    }

}