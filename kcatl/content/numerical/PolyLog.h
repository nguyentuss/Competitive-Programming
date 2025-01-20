/**
 * Author: Tomatoes
 * Date: 2023-10-09
 * Source: Unknown
 * Description: Logarithm of a polynomial modulos MOD
 * Time: O(n \log^2 n)
 * Status:
 *  - tested on https://judge.yosupo.jp/problem/log_of_formal_power_series
 */
#pragma once

#include "NumberTheoricTransform.h"
#include "PolyInv.h"

vl polyDeriv(vl a) {
	rep(i,0,sz(a)) a[i] = a[i] * i % mod;
	a.erase(a.begin()); return a;
}
vl polyPrim(vl a) {
	rep(i,0,sz(a)) a[i] = a[i] * modinv(i + 1) % mod;
	a.insert(a.begin(), 0); return a;
}
vl polyLog(const vl& a) {
	if (sz(a) == 1) return {0};
	vl res = polyPrim(conv(polyDeriv(a), polyInv(a)));
	res.resize(sz(a)); return res;
}
