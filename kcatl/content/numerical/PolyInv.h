/**
 * Author: Tomatoes
 * Date: 2023-11-23
 * License: CC0
 * Description: Inverse of a polynomial modulos MOD
 * Time: O(n \log^2 n)
 * Status:
 *  - tested on https://judge.yosupo.jp/problem/inv_of_formal_power_series
 */
#pragma once

#include "NumberTheoricTransform.h"

ll modinv(ll b) {return modpow(b, mod - 2);}
vl polyInv(const vl& a) {
	vl b = {modinv(a[0])}; while (sz(b) < sz(a)) {
		vl a_cut(a.begin(), a.begin() + min(sz(a), sz(b)*2));
		vl x = conv(conv(b, b), a_cut);
		b.resize(sz(b)*2);
		rep(i,sz(b)/2,min(sz(x),sz(b))) b[i] = x[i] ? mod-x[i] : 0;
	} b.resize(sz(a)); return b;
}
