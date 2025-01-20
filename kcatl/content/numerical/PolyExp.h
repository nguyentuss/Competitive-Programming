/**
 * Author: Tomatoes
 * Date: 2023-10-09
 * Source: Unknown
 * Description: Exponent of a polynomial modulos MOD
 * Time: O(n \log^3 n)
 * Status:
 *  - tested on https://judge.yosupo.jp/problem/exp_of_formal_power_series
 */
#pragma once

#include "NumberTheoricTransform.h"
#include "PolyLog.h"

vl polyExp(const vl& a) {
	vl b = {1}; b.reserve(1 << (32 - __builtin_clz(sz(a) - 1)));
	while (sz(b) < sz(a)) {
		vl x(a.begin(), a.begin() + min(sz(a), sz(b)*2));
		x[0] = 1; b.resize(sz(b)*2); vl ln = polyLog(b);
		rep(i,0,sz(x)) x[i] -= ln[i], x[i] += (x[i] < 0) * mod;
		b.resize(sz(b)/2); x = conv(x, b); b.resize(sz(b)*2);
		rep(i, sz(b)/2, sz(b)) b[i] = x[i];
	} b.resize(sz(a)); return b;
}
