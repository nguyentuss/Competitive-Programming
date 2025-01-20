/**
 * Author: tomatoes
 * Date: 2023-07-12
 * Source: https://github.com/yosupo06/library-checker-problems/blob/master/math/subset_convolution/sol/correct.cpp
 * Description: Calculate $\displaystyle c[z] = \sum\nolimits_{x\&y=0,x|y=z} a[x] \cdot b[y]$.
 * Time: O(N^2 2^N)
 * Status: tested on yosupo:subset_convolution
 */

template<class T>
void sos(int n, vector<T>& a, bool inv) {
	rep(k,0,n) rep(i,0,1<<n) if (i & (1 << k)) {
		if (inv) a[i] -= a[i ^ (1 << k)];
		else a[i] += a[i ^ (1 << k)];
	}
}

template<class T>
vector<T> conv(int n, vector<T> a, vector<T> b) {
	vector<vector<T>> f(n + 1, vector<T>(1 << n)), g = f;
	rep(i,0,1<<n) {
		int k = __builtin_popcount(i);
		f[k][i] = a[i]; g[k][i] = b[i];
	}
	rep(k,0,n+1) sos(n, f[k], 0), sos(n, g[k], 0);
	rep(k,0,n+1) {
		a.assign(1 << n, 0);
		rep(l,0,k+1) rep(i,0,1<<n) a[i] += f[l][i] * g[k-l][i];
		sos(n, a, 1);
		rep(i,0,1<<n) if (__builtin_popcount(i) == k) b[i] = a[i];
	}
	return b;
}

