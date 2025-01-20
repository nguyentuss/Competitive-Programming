/**
 * Author: Tomatoes
 * Date: 2023-10-09
 * Source: Unknown
 * Description: Division of two polynomial modulo MOD
 * Time: O(n \log^2 n)
 * Status:
 *  - tested on https://judge.yosupo.jp/problem/division_of_polynomials
 *  - tested on https://judge.yosupo.jp/problem/multipoint_evaluation
 */
#pragma once

#include "NumberTheoricTransform.h"
#include "PolyInv.h"

vl polyDiv(vl a, vl b) {
	int n = sz(a), m = sz(b); if (n < m) return {};
	reverse(all(a)); reverse(all(b)); b.resize(n - m + 1);
	a = conv(a, polyInv(b));
	a.erase(a.begin() + n - m + 1, a.end());
	reverse(all(a)); return a;
}
vl polyMod(const vl& a, const vl& b) {
	if (sz(a) < sz(b)) return a;
	vl c = conv(polyDiv(a, b), b), res(sz(b) - 1, 0);
	rep(i, 0, sz(b)-1) res[i] = a[i]-c[i] + (a[i]<c[i])*mod;
	return res;
}
