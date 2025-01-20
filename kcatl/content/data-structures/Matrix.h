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
	Matrix(int n, int m) : n(n), m(m), d(n, vector<T>(m)) {}
	Matrix operator*(const Matrix& o) const {
		assert(m == o.n); Matrix a(n, o.m);
		rep(i,0,n) rep(k,0,m) rep(j,0,o.m) // order matters
			a.d[i][j] += d[i][k] * o.d[k][j];
		return a;
	}
	vector<T> operator*(const vector<T>& vec) const {
		assert(m == sz(vec)); vector<T> a(n);
		rep(i,0,n) rep(j,0,m) a[i] += d[i][j] * vec[j];
		return a;
	}
	Matrix operator^(ll e) const {
		assert(e >= 0 && n == m); Matrix a(n, n), b(*this);
		rep(i,0,n) a.d[i][i] = 1;
		for (; e; e >>= 1, b = b * b) if (e & 1) a = a * b;
		return a;
	}
};

