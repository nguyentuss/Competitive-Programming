/**
 * Author: Myself
 * Date: 2023-10-09
 * Source: Modified from multipoint
 * Description: Evaluate a polynomial at multiple points
 * Time: O(n \log^2 n)
 * Usage: vl y = polyMultiEval(p, x);
 * Status:
 *  - tested on https://judge.yosupo.jp/problem/polynomial_interpolation
 */
#pragma once

#include "NumberTheoricTransform.h"
#include "PolyMultipoint.h"

vl interpolate(const vl& X, const vl& Y) {
	int n = X.size(); // assert(n == sz(Y)); // assert(all x are distinct)
	
	if (X.empty()) return {};
	vector<vector<vl>> ps = evalTree(X);
	vl pdiff = polyDeriv(ps[sz(ps) - 1][0]);
	vl pi = polyMultiEval(pdiff, X, ps);

	vector<vl> res(sz(ps[0]));
	rep(i,0,sz(ps[0])) 
		res[i] = {Y[i] * modinv(pi[i]) % mod};
	
	rep(i,0,sz(ps)-1) {
		vector<vl> nxt;
		for (int j = 0; j < sz(ps[i]); j += 2) {
			if (j+1 < sz(ps[i])) {
				vl p1 = conv(ps[i][j+1], res[j]);
				vl p2 = conv(ps[i][j], res[j+1]);
				rep(k,0,sz(p1)) 
					if ((p1[k] += p2[k]) >= mod) p1[k] -= mod;
				nxt.push_back(p1);
			} else nxt.push_back(res[j]);
		}
		swap(nxt, res);
	}
	return res[0];
}