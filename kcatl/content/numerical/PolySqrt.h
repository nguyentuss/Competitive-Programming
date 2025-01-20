/**
 * Author: tahp
 * Date: 2023-10-09
 * Source: Unknown
 * Description: Fast poly sqrt, idea can be applied for cbrt...
 * Time: O(n \log^3 n)
 * Status:
 *  - tested on https://judge.yosupo.jp/problem/sqrt_of_formal_power_series
 */
#pragma once

#include "NumberTheoricTransform.h"
#include "../number-theory/ModLog.h"
#include "PolyInv.h"

vl polySqrt(const vl &a){ // g*g = f => g ~= (f - g^2) * g^(-1)
	if (*max_element(all(a)) == 0) return a;
	int pw = 0; while (a[pw] == 0) ++pw;
	ll dlog = modLog(root, a[pw], mod);
	if (dlog % 2 || pw % 2) return {-1};
	vl b(a.begin() + pw, a.end()), res(1, 1);
	ll inv = modinv(a[pw]), inv2 = modinv(2);
	rep(i, 0, sz(b)) b[i] = b[i] * inv % mod;
	b.resize(sz(a));
	while (sz(res) < sz(b)) {
		int nsz = min(sz(res) * 2, sz(b));
		vl c = conv(res, res); c.resize(nsz);
		rep(i, 0, nsz) c[i] = b[i] - c[i] + (b[i] < c[i]) * mod;
		c = conv(c, polyInv(res));
		rep(i, sz(res), nsz) res.push_back(c[i] * inv2 % mod);
	}
	res.insert(res.begin(), pw / 2, 0);
	ll coef = modpow(root, dlog / 2);
	rep(i, 0, sz(res)) res[i] = coef * res[i] % mod;
	res.resize(sz(a)); return res;
}
