/**
 * Author: Tomatoes
 * Date: 2023-11-01
 * Source: https://github.com/NyaanNyaan/library/blob/master/fps/taylor-shift.hpp
 * Description: Shift a polynomial $a(x)$ to $a(x + k)$.
 * Time: O(n \log n)
 * Status:
 *  - tested on https://judge.yosupo.jp/problem/polynomial_taylor_shift
 */
#pragma once

#include "NumberTheoricTransform.h"

vl polyShift(const vl& a, ll k) {
	int n = sz(a); vl b(n), c(n); b[n-1]=a[0]; c[0]=1; ll f = 1;
	rep(i,1,n) {
		f = f * i % mod; b[n - i - 1] = a[i] * f % mod;
		c[i] = c[i - 1] * k % mod * modinv(i) % mod;
	}
	b = conv(b, c); f = modinv(f);
	rep(i,0,n) c[n-i-1] = b[i] * f % mod, f = f * (n-i-1) % mod;
	return c;
}
