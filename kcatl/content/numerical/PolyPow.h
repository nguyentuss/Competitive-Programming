/**
 * Author: Tomatoes
 * Date: 2023-10-09
 * Source: Unknown
 * Description: k-th power of a polynomial modulos MOD.
 * Time: O(n \log^3 n)
 * Status:
 *  - tested on https://judge.yosupo.jp/problem/pow_of_formal_power_series
 */
#pragma once

#include "NumberTheoricTransform.h"
#include "PolyLog.h"
#include "PolyExp.h"

vl polyPower(const vl& a, ll k) {
	if (k == 0) {vl b(sz(a), 0); b[0] = 1; return b;}
	if (*max_element(all(a)) == 0) return a;
	ll pw = 0; vl b = a; while (a[pw] == 0) ++pw;
	if (pw > sz(a) / k) return vl(sz(a), 0);
	rotate(b.begin(), b.begin() + pw, b.end());
	ll coef = b[0], inv = modinv(coef);
	for (ll &x : b) x = x * inv % mod;
	b = polyLog(b);
	for (ll &x : b) x = x * (k % mod) % mod;
	b = polyExp(b);
	coef = modpow(coef, k % (mod - 1));
	vl res(sz(a), 0); pw *= k;
	rep(i,0,sz(b)) if (i + pw < sz(a))
		res[i + pw] = 1ll * coef * b[i] % mod;
	return res;
}

